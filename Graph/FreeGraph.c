#include "../include/libgraph.h"
/*-----------------------------------------------------------------------------*
| FreeGraph: libera la memoria allocata per una struttura di tipo GRAPH        |
|                                                                              |
|                                                                              |
| Data creazione: 29/01/2009                              Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/
void FreeGraph
(
   GRAPH *Graph
)
{
   int i;
   int AlNodes;         // numero nodi allocati
   GRAPH_NODE *Curr;    // puntatore a nodo di un grafo
   ARK *TmpArk;         // puntatore di supporto per lo scorrimento di una lista
                        // di archi
      
   AlNodes= Graph->TotNodes+Graph->MaxAllocNode;
   Curr=Graph->StartNode;
   for(i=0;i<AlNodes;i++)  // libera tutti gli archi
   {
      while(Curr[i].Ark!=NULL)
      {
         TmpArk=Curr[i].Ark;
         Curr[i].Ark=TmpArk->NextArk;
         free(TmpArk);
      }
      if(Curr[i].Node!=NULL)// libera tutti i nodi allocati
         free(Curr[i].Node);
   }
   free(Graph->StartNode);  // libera l'array
   Graph->StartNode=NULL;
   Graph->TotNodes=0;
}
