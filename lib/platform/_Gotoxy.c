#include "platform.h"
/*-----------------------------------------------------------------------------*
| _Gotoxy: versione a priorità elevata della function Gotoxy                   |
| Se il sistema è Linux, avviene il posizionamento tramite appositi tag nel    | 
| "fprintf", altrimenti utilizziamo la parte di codice del gotoxy di "conio.h" |
| non funzionante nelle nuove versioni di wxdev.                               |
| Sono state utilizzate le function del set di  API "Win32".                   |
| Creazione: 13/01/2009                 Autori: Arcadio Ciro e Cittadini Paolo |
*-----------------------------------------------------------------------------*/
void  _Gotoxy
(
   int x, 
   int y
)
{
   #ifdef _GNU_SOURCE
   fprintf(stderr,"\e[%d;%dH", x, y);
   #else
   HANDLE hConsoleOutput;
   COORD dwCursorPosition;
   dwCursorPosition.X = y;
   dwCursorPosition.Y = x;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
   #endif
}
