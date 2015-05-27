#include "../include/libtree.h"
/*-----------------------------------------------------------------------------*
| Function per la visita in profondità dell'albero binario                     |
|                                                                              |
|                                                                              |
|                                                                              |
| Data creazione: 04/01/2008                           Autore: Paolo Cittadini |
*-----------------------------------------------------------------------------*/
void HeightVisit
(
   TREE *Tree,   //albero binario
   int *c        //c --> LIVELLO
)
{   
   if(Tree!=NULL)//se il nodo attuale non punta a NULL
   {
      (*c)++;//nuovo livello
      if(Tree->Right!=NULL)//scorrimento in profondità a destra
         HeightVisit(Tree->Right,c);
      if(Tree->Left!=NULL)//scorrimento in profondità a sinistra
         HeightVisit(Tree->Left,c);
   }
}

