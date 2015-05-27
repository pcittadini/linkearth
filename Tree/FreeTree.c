#include "../include/libtree.h"
/*-----------------------------------------------------------------------------*
| FreeTree: libera la memoria precedentemente allocata per una struttura di    |
|           tipo TREE.                                                         |
|                                                                              |
|           dato un nodo root, esplora l'albero in profondita'e libera la      |
| memoria riservata a tutte le foglie.                                         |
|                                                                              |
| data di creazione: 26/01/09                           autore: Arcadio Ciro   |
*-----------------------------------------------------------------------------*/
void FreeTree
(
   TREE** Root
)                                                                              
{
   if((*Root)!=NULL)
   {
      FreeTree(&(*Root)->Left);  // scorre l'albero a sinistra
      FreeTree(&(*Root)->Right); // scorre l'albero a destra
      free(*Root);               // libera la memoria riservata al nodo corrente
   }
}
