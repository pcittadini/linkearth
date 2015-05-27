#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| DispPopup: visualizza un piccolo popup per l'inserimento di dati in una      |
|                                                                              |
|                                                                              |
| data di creazione: 14/01/2009                           Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/

void DispPopup()
{
  int i;
/*-----------------------------------------------------------------------------*
|/////////////////////////////////POPUP////////////////////////////////////////|
*-----------------------------------------------------------------------------*/
   SetColor(TXT,BKGRND);
   Gotoxy(3,16);
   printf("*----------------------------------------------*");
   for(i=1;i<=16;i++)   
   {
      Gotoxy(3+i,15);
      CPrintf("%b ",BLACK);
      SetColor(TXT,BKGRND);
      printf("|                                              |");
   }
   
   Gotoxy(20,15);
   CPrintf("%b ",BLACK);
   SetColor(TXT,BKGRND);
   printf("*----------------------------------------------*");
   Gotoxy(21,15);
   CPrintf("%b                                                ",BLACK);
   TextReset();
}
