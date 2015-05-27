#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| _DispBackground: visualizza un background. (versione a priorita' elevata)    |
|                                                                              |
| data di creazione: 13/01/2009                           Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/
void _DispBackground()
{
   _SetColor(TXT,BKGRND);
   _Gotoxy(2,2);fprintf(stderr,"*------------------------------------");
               fprintf(stderr,"-------------------------------------*");
   _Gotoxy(3,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(4,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(5,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(6,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(7,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(8,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(9,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(10,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(11,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(12,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(13,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(14,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(15,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(16,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(17,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(18,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(19,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(20,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(21,2);fprintf(stderr,"|                                    ");
               fprintf(stderr,"                                     |");
   _Gotoxy(22,2);fprintf(stderr,"*------------------------------------");
               fprintf(stderr,"-------------------------------------*");
   _TextReset();
}
