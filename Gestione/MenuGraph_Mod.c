#include "../include/libgraph.h"
#include "../lib/platform/platform.h"
#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| MenuGraph_Mod: struttura per menu interattivo                                |
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
| Data creazione: 29/01/2009                            Autore: Paolo Cittadini|
*-----------------------------------------------------------------------------*/
void MenuGraph_Mod
(
   GRAPH *Grafo    // il grafo viene passato alla funzione
)
{
   int i,j;        // indici e variabili di stato
   int Exit, Stop;
   
   i=0;            // inizializzazione variabili
   j=0;
   Exit=0;
   Stop=0;
   
   do
   {
      DispPopup();                    // MOSTRA IL POPUP
      DispForeground(MenuGRAPH_MOD,i);// disegna il foreground per il menù
      
      switch(GetKey())// si effettua lo switch dei tasti direzionali
      {
         case UP   : if(i!=0)  //viene gestito il movimento all'interno del menu
                        i-=2;
                     break;
         case DOWN : if(i<10)
                        i+=2;
                     break;
         case ENTER: switch(i)
                     {
                        case 0 : MenuGraph_Mod_LD(Grafo); //manù aggiungi LD
                                 break;
                        case 2 : MenuGraph_Mod_AddNode(Grafo);//Nuovo Nodo
                                 break;
                        case 4 : MenuGraph_Mod_Ark(Grafo);//Nuovo Arco
							            break;
						      case 6 : MenuGraph_Mod_Hub(Grafo);//Nuovo HUB
							            break;
						      case 8 : MenuGraph_Mod_Delete(Grafo);//Elimina Nodo
                                 break;
                        case 10: Exit=1; //exit
                                 break;
                     }
                     break;
         case BACKSPACE:Exit=1; //backspace per uscire dal menù
                        break;
      }
   }while(!Exit);// fino a che non è asserita la flag d'uscita
}
