#include "platform.h"
/*-----------------------------------------------------------------------------*
| Getch: procedura per l'acquisizione di un carattaere da tastiera.            | 
| Se il sistema in uso è Microsoft, viene utilizzata la routine _getch di      |
| conio.h, altrimenti viene utilizzato un metodo per il freeze della shell e   |
| l'interruzione del line buffer di tastiera, in questo modo il getchar viene  |
| bloccato al primo inserimento.                                               |
| La parte di codice per Linux è stata estratta da una libreria non ufficiale  |
| ditribuita sotto licenza GNU/GPL.                                            |
|                                                                              |
| _Getch:limita il buffer della Getchar() all'acquisizione di un solo carattere|
| (NON funziona come il Getch);                                                |  
|                                                                              |
| Creazione: 24/10/2008                 Autori: Arcadio Ciro e Cittadini Paolo |
*-----------------------------------------------------------------------------*/
/*CRONOLOGIA MODIFICHE*/
/*-----------------------------------------------------------------------------*
| [+]Aggiunta function _Getch                                     [20.11.2008] |
*-----------------------------------------------------------------------------*/

int  Getch()
{
   #ifdef _GNU_SOURCE
   struct termios oldt,
					   newt;
   int ch;

   tcgetattr( STDIN_FILENO, &oldt );
   newt = oldt;
   newt.c_lflag &= ~( ICANON | ECHO );
   tcsetattr( STDIN_FILENO, TCSANOW, &newt );
   
   ch = getchar();

   tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
   
   return ch;
   
   #else
   _getch();
   #endif
}

int _Getch()
{
   char buf[256];
   int bufp=0;
   return (bufp>0) ? buf[--bufp] : getchar();
}

