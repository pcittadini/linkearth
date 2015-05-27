#include "platform.h"
/*-----------------------------------------------------------------------------*
| ClearScreen: function multipiattaforma per la pulizia del testo sul video    |
|                                                                              |
| Creazione: 24/10/2008                 Autori: Arcadio Ciro e Cittadini Paolo |
*-----------------------------------------------------------------------------*/
void ClearScreen()
{
   #ifdef _GNU_SOURCE
   system("clear");   // sistemi Unix
   #else
   system("cls");     // Microsoft e BSD
   #endif
}
