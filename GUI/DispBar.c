#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| DispBar: disegna una barra di caricamento. [deprecated]                      |
|                                                                              |
| 26/01/09                                                Arcadio Ciro         |
*-----------------------------------------------------------------------------*/

void DispBar
(
   int x,
   int y,
   int Max,
   int Actual
)
{
   int i;
   int Per;

      if(Max>40)
      {
         Max=Max/40;
         Per=40-(Actual/Max);
      }
      else
      {
         Per=((40/Max)*Actual);
         Per=40-Per;
      }

   Gotoxy(x,y);
   SetColor(BLUE,BLUE);
   for(i=0;i<Per;i++)
      fprintf(stderr," ");
   SetColor(WHITE,WHITE);
   for(i=0;i<40-Per;i++)
      fprintf(stderr," ");

   TextReset();
}
