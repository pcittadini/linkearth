#include "platform.h"
/*-----------------------------------------------------------------------------*
| Yawn: resa portabile la syscall sleep.                                       |
| Creazione: 06/11/2008                 Autori: Arcadio Ciro e Cittadini Paolo |
*-----------------------------------------------------------------------------*/
void Yawn
(
   float Time
)
{
#ifdef _GNU_SOURCE
   sleep(Time);
#else
   Time=Time*1000;
   Sleep(Time);
#endif
}
