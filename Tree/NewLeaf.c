#include "../include/tree.h"
#include <string.h>
/*-----------------------------------------------------------------------------*
| NewLeaf: alloca un nuovo elemento e lo aggiunge alla struttura               |
|                                                                              |
|                                                                              |
| Data creazione: 15/12/2008                              Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/

int NewLeaf
(
   TREE **Tree
)
{
   TREE *Tmp;
   int Error;  // memoria insufficiente
   
   Tmp=(TREE*)malloc(sizeof(TREE));
   if(Tmp!=NULL)
   {
      // inizializza campi
      strcpy(Tmp->City,"\0");
      Tmp->Region=0;
      Tmp->Lat=0;
      Tmp->Long=0;
      // inizializza figli
      Tmp->Right= NULL;
      Tmp->Left = NULL;
      
      *Tree=Tmp; // aggiunge nodo alla struttura
   }
   else
      Error=1; // memoria insufficiente
      
   return Error;
}
