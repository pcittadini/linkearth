#include "../include/libgraph.h"
#include "../lib/platform/platform.h"
#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| MenuGraph: struttura per menu interattivo                                    |
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
| Data creazione: 29/01/2009                              Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/
void MenuGraph
(
   GRAPH *Grafo
)
{
   int i;
   int Exit;
   
   i=0;
   Exit=0;
   
   do
   {
      DispPopup();                 // disegna il background
      DispForeground(MenuGRAPH,i); // disegna info di foreground
      
      switch(GetKey())
      {
         case UP   : if(i!=0)  //viene gestito il movimento all'interno del menu
                        i-=2;
                     break;
         case DOWN : if(i<6)
                        i+=2;
                     break;
         case ENTER: switch(i)
                     {
                        case 0 : MenuGraph_View(Grafo); // avvia menu visualizza
                                 break;                 // grafo
                        case 2 : MenuGraph_Mod(Grafo);  // avvia menu modifica
                                 break;
                        case 4 : MenuGraph_Path(Grafo); // avvia menu cerca
                                 break;                 // cammino
                        case 6:  Exit=1;
                                 break;
                     }
                     break;
         case BACKSPACE:Exit=1;
                        break;
      }
   }while(!Exit);
}
