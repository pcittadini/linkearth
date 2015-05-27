#include "../include/libtree.h"
#include "../lib/platform/platform.h"
#include "../include/GUI.h"
#include <math.h>
/*-----------------------------------------------------------------------------*
| Menù di visualizzazione estrazione dall'albero                               |
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
void MenuTree_Level
(
   TREE* Tree, //accetta l'albero carico
   int Height, //altezza dell'albero
   int* Level  //livello da estrarre
)
{
   int Exit;   //varibili locali di indice e di stato
   int i;
   i=*Level;   //l'indice viene inizializzato al livello
   Exit=0;
   
   SetColor(HTXT,HBKGRND);  //setta colorazione menù
   Gotoxy(16,37),printf("<");//indicatori direzionali
   Gotoxy(16,42),printf(">");
   do
   {
      SetColor(TXT,BKGRND); //setta colorazione
      Gotoxy(16,38);
      printf("%4d",i);
      Gotoxy(19,28);
      printf("numero di elementi:%6g",pow(2,i));
      TextReset();
      Gotoxy(22,76);
      
      switch(GetKey())//switch delle opzioni
      {
         case LEFT:  if(i>0)
                        i--;
                     break;
         case RIGHT: if(i<(Height-1))
                        i++;
                     break;
         case ENTER: *Level=i;
                     Exit=1; 
                     break;
         case BACKSPACE: Exit=1;
                         break;
      }
   }while(!Exit);
}
