#include "../include/libgraph.h"
/*-----------------------------------------------------------------------------*
| NewNode: Alloca un nodo per la struttura grafo                               |
|                                                                              |
|          Alloca blocchi di dimensione "BATCH_NODE". Quando "MaxAllocNode"    |
| e' pari a 0, non ci sono celle libere, quindi si procede con l'allocazione   |
| di un nuovo blocco. In caso contrario, MaxAllocNode viene semplicemente      |
| decrementato e una delle celle libere potrà essere occupata.                 |
|                                                                              |
| Data creazione: 28/01/2008                           Autore: Arcadio Ciro    |
*-----------------------------------------------------------------------------*/
void NewNode
(
   GRAPH *CityGraph,
   int *MaxAllocNode,
   int Size
)
{
   int i;
   
   if (!(*MaxAllocNode))
   {
      CityGraph->StartNode=
      (GRAPH_NODE*)realloc(CityGraph->StartNode,(BATCH_NODE+Size)*sizeof(GRAPH_NODE));
      for(i=Size;i<(BATCH_NODE+Size);i++)
      {
         CityGraph->StartNode[i].Node=NULL;
         CityGraph->StartNode[i].Ark=NULL;
         CityGraph->StartNode[i].Visited=-1;
      }

      *MaxAllocNode=(BATCH_NODE-1);
   }
   else
      (*MaxAllocNode)--;
}


   
      
