#include "../include/libtree.h"
/*-----------------------------------------------------------------------------*
| LeafToStack: dall'albero allo STACK                                          |
|                                                                              |
| Data creazione: 02/01/2008                           Autore: Paolo Cittadini |
*-----------------------------------------------------------------------------*/
void LeafsToStack
(
   TREE **Tree,  //albero binario
   STACK **Leafs,//stack
   int Height,   //altezza
   int Level     //livello
)
{     
   if (Height==Level) //se l'altezza in esplorazione corisponde al livello da estrarre
   {
      Push_STACK(*Tree,Leafs); //push sullo stack dell'elemento root
      if(*Tree)                //se non punta a null
      {
         if((*Tree)->Left)     //scorrimento in ampiezza
         {                     //con prelievo e liberazione della memoria
            FreeTree(&(*Tree)->Left);
            (*Tree)->Left=NULL;
         }
         if((*Tree)->Right)
         {
            FreeTree(&(*Tree)->Right);
            (*Tree)->Right=NULL;
         }
      }
   }
   else
   {  //se non è il livello da estrarre scendiamo in profondità e liberiamo gli elementi visitati
      LeafsToStack(&(*Tree)->Left,Leafs,Height-1,Level);
      LeafsToStack(&(*Tree)->Right,Leafs,Height-1,Level);
      free(*Tree);
      *Tree=NULL;
   }
}

