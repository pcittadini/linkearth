#include "../lib/platform/platform.h"
#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| Menù per la gestione del layout di visualizzazione                           |
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
void MenuOption()
{
   int i;   //indice e flag
   int Exit;
   
   i=0;     //inizializzazioni
   Exit=0;
      
   do
   {
      DispPopup(); //display del popup
      DispForeground(MenuOPT,i); //costruisci il foreground corrispondente
      
      switch(GetKey())//viene gestito il movimento all'interno del menu
      {
         case UP   : if(i!=0)   // UP , opzione superiore
                        i-=2;
                     break;
         case DOWN : if(i<8)    // DOWN , opzione inferiore
                        i+=2;
                     break;
         case ENTER: switch(i)  // SCELTA con ENTER, switch delle impostazioni
                     {
                        case 0 : TXT=BLACK;      //primo layout
                                 BKGRND=CYAN;
                                 HTXT=YELLOW;
                                 HBKGRND=MAGENTA;
                                 break;
                        case 2 : TXT=BLACK;      //secondo layout
                                 BKGRND=WHITE;
                                 HTXT=WHITE;
                                 HBKGRND=RED;
                                 break;
                        case 4 : TXT=GREEN;      //terzo layout
                                 BKGRND=BLACK;
                                 HTXT=BLACK;
                                 HBKGRND=GREEN;
                                 break;
                        case 6 : TXT=WHITE;      //quarto layout
                                 BKGRND=BLUE;
                                 HTXT=WHITE;
                                 HBKGRND=RED;
                                 break;
                        case 8 : Exit=1;         //USCITA
                     }
                     break;
         case BACKSPACE:Exit=1; // backspace per uscire
                        break;
      }
   }while(!Exit); //fino all'asserimento di EXIT
}
