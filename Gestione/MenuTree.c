#include "../include/libtree.h"
#include "../lib/stack/stack.h"
#include "../lib/platform/platform.h"
#include "../include/GUI.h"
#include <math.h>
/*-----------------------------------------------------------------------------*
| Menù per la gestione della visualizzazione dell'albero                       |
|                                                                              |
|            Tramite un indice, permette l'interazione e la selezione di       || una lista di funzioni con un semplice input da tastiera.                     |
|                                                                              |
|            ENTER:     accetta/avanti                                         |
|            BACKSPACE: annulla/indietro                                       |
|            UP:        sposta cursore su                                      |
|            DOWN:      sposta cursore giu'                                    |
|            LEFT:      sposta cursore a sinistra                              |
|            RIGHT:     sposta cursore a destra                                |
|                                                                              |
| Ultima modifica: 28/01/2009                           Autore: Paolo Cittadini|
*-----------------------------------------------------------------------------*/
void MenuTree
(
   STACK **Stack //accetta in input lo STACK degli elementi
)
{
   int i;        //indice
   int TotLeafs; //foglie caricate nello stack
   int Exit;     //flag d'uscita
   int Stop;     
   int Height;   //altezza albero
   int Level;    //indice di livello
   TREE *Tree;   //albero d'appoggio
   
   i=0;          //inizializzazioni
   TotLeafs=0;
   Exit=0;
   Stop=0;
   Tree=NULL;
   
   if(LcOpen(&Tree)) //se il caricamento nell'albero non è andato a buon fine
      Exit=1;
   else     
   {
      HeightVisit(Tree,&TotLeafs); //visita in profondità
      Height=log2(TotLeafs);       //calcola altezza in base al numero di foglie
      Level=Height-1;              //
   }
      
   while(!Exit)
   {
      DispPopup(); //construisci il POPUP
      DispForeground(MenuTREE,i);//construisci il foreground
      
      switch(GetKey())//viene gestito il movimento all'interno del menu
      {
         case UP   : if(i!=0)  //caso UP
                        i-=2;
                     break;
         case DOWN : if(i<4)  //caso DOWN
                        i+=2;
                     break;
         case ENTER: switch(i) //se ENTER, entra nel menu corrispondente
                     {
                        case 0 : MenuTree_View(Tree,Tree,5,39,4,1,&Stop);
                                 //vista di esplorazione
                                 break;
                        case 2 : MenuTree_Level(Tree,Height,&Level);
                                 //vista di estrazione
                                 break;
                        case 4 : LeafsToStack(&Tree,Stack,Height,Height-Level);
                                 //caricamento nello stack del livello
                                 Exit=1;
                                 break;
                     }
                     break;
         case BACKSPACE:if(Stack) //se lo stack di input è PIENO
                           Free_STACK(Stack); //libera la memoria
                        Exit=1;   //esci
                        break;    //stop dello switch
      }
   }
}
