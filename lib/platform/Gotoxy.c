#include "platform.h"
/*-----------------------------------------------------------------------------*
| Gotoxy: per il posizionamento del cursore sullo schermo date le coordinate.  |
| Se il sistema è Linux, avviene il posizionamento tramite appositi tag nel    | 
| "printf", altrimenti utilizziamo la parte di codice del gotoxy di "conio.h", |
| non funzionante nelle nuove versioni di wxdev.                               |
| Sono state utilizzate le function del set di  API "Win32".                   |
| Creazione: 24/10/2008                 Autori: Arcadio Ciro e Cittadini Paolo |
*-----------------------------------------------------------------------------*/
/*CRONOLOGIA MODIFICHE*/
/*-----------------------------------------------------------------------------*
| [+]Invertite x e y, per riferimento UNIX.                       [06.11.2008] |
*-----------------------------------------------------------------------------*/
void  Gotoxy
(
   int x, 
   int y
)
{
   #ifdef _GNU_SOURCE
   printf("\e[%d;%dH", x, y);
   #else
   HANDLE hConsoleOutput;
   COORD dwCursorPosition;
   dwCursorPosition.X = y;
   dwCursorPosition.Y = x;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
   #endif
}
