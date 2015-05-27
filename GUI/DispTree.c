#include "../include/GUI.h"
#include <math.h>

/*-----------------------------------------------------------------------------*
| DispBackground: visualizza un albero di altezza "Level"                      |
|                                                                              |
| data di creazione: 29/12/2008                           Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/
void DispTree
(
   TREE *Root,
   int i,
   int j,
   int Level
)
{
   int Step;
   int t;
   int x,y;

   if(Root!=NULL)
   {
      x=i;
      y=j;
      _Gotoxy(i,j);
      if(!Level)
         fprintf(stderr,"O");
      else
      {
         if (Level<3)
            switch(Level)
            {
               case 2: Step=3;break;
               case 1: Step=2;break;
            }
         else
            Step=(Level*(Level-1));
         fprintf(stderr,"O");
         if(Root->Left!=NULL)
         {  
            _Gotoxy(i+1,j-Step);
            fprintf(stderr,"|");
            _Gotoxy(i,j-Step);
            for(t=0;t<Step;t++)
               fprintf(stderr,"_");
            DispTree(Root->Left,i+2,j-Step,Level-1);
            i=x;
            j=y;
         }
         if(Root->Right!=NULL)
         {
            _Gotoxy(i,j+1);
            for(t=0;t<Step;t++)
               fprintf(stderr,"_");
            _Gotoxy(i+1,j+Step);
            fprintf(stderr,"|"); 
            DispTree(Root->Right,i+2,j+Step,Level-1);
         }
      }
   }
}
