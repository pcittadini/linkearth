#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| Splash: function per la stampa a video dello splash screen                   |
|                                                                              |
|                                                                              |
| Ultima modifica: 26/11/2008                          Autore: Paolo Cittadini |
*-----------------------------------------------------------------------------*/

void Splash()
{  //construisce il background
   DispBackground();
   //setta la colorazione 
   SetColor(HBKGRND,BKGRND);
   
   
Gotoxy(5,10); printf("                _-o#&&*''''?d:>b\\_");
Gotoxy(6,10); printf("          _o/'`''  '',, dMF9MMMMMHo_");
Gotoxy(7,10); printf("       .o&#'        `'MbHMMMMMMMMMMMHo.");
Gotoxy(8,10); printf("     .o'' '         vodM*$&&HMMMMMMMMMM?.");
Gotoxy(9,10); printf("    ,'              $M&ood,~'`(&##MMMMMMH\\");
Gotoxy(10,10);printf("   /               ,MMMMMMM#b?#bobMMMMHMMML");
Gotoxy(11,10);printf("  &              ?MMMMMMMMMMMMMMMMM7MMM$R*Hk");
Gotoxy(12,10);printf(" ?$.            :MMMMMMMMMMMMMMMMMMM/HMMM|`*L");
Gotoxy(13,10);printf("|               |MMMMMMMMMMMMMMMMMMMMbMH'   T,");
Gotoxy(14,10);printf("$H#:            `*MMMMMMMMMMMMMMMMMMMMb#}'  `?");
Gotoxy(15,10);printf("]MMH#             ""*""""*#MMMMMMMMMMMMM'    -");
Gotoxy(16,10);printf("MMMMMb_                   |MMMMMMMMMMMP'     :");
Gotoxy(17,10);printf("HMMMMMMMHo                 `MMMMMMMMMT       .");
Gotoxy(18,10);printf("?MMMMMMMMP                  9MMMMMMMM}       -");
Gotoxy(19,10);printf("-?MMMMMMM                  |MMMMMMMMM?,d-    '");
Gotoxy(20,10);printf(" :|MMMMMM-                 `MMMMMMMT .v|.   :");

   
   
   
   
   SetColor(TXT,BKGRND);
                                      
   Gotoxy(5,9);  printf("ArCiSoft's");
   Gotoxy(6,26);  printf(" _ _       _");
   Gotoxy(7,26);  printf("| (_)_ __ | | __");
   Gotoxy(8,26);  printf("| | | '_ \\| |/ /");         
   Gotoxy(9,26);  printf("| | | | | |   < ");      
   Gotoxy(10,26); printf("|_|_|_| |_|_|\\_\\______           _   _");
   Gotoxy(11,42); printf("|  ___|         | | | |");
   Gotoxy(12,42); printf("| |__  __ _ _ __| |_| |__");
   Gotoxy(13,42); printf("|  __|/ _` | '__| __| '_ \\");
   Gotoxy(14,42); printf("| |__| (_| | |  | |_| | | |");
   Gotoxy(15,42); printf("\\____/\\__,_|_|   \\__|_| |_|");
                 
   //SYSTEM è definita in platform.h
   Gotoxy(16,58);  
   printf("%-7s", SYSTEM);
   printf("v 1.0");
  // Gotoxy(21,38);  printf("by Arcadio Ciro & Cittadini Paolo");
   Gotoxy(22,76);
   Getch();                                                             
}
