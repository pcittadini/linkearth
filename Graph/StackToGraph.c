#include "../include/libgraph.h"
#include "../lib/stack/libstack.h"

/*-----------------------------------------------------------------------------*
| StackToGraph: crea un grafo a partire da uno stack                           |
|                                                                              |
|               per ogni elemento dello stack, alloca un nuovo nodo nel grafo. |
| Al termine, inizializza le dimensioni del grafo al valore corretto e crea    |
| una struttura di archi di tipo circolare (ogni nodo è collegato al successivo|
| e al precedente).                                                            |
|                                                                              |
| Data creazione: 28/01/2008                           Autore: Arcadio Ciro    |
*-----------------------------------------------------------------------------*/
void StackToGraph
(
   STACK **Leafs,    // Stack contenente i nodi
   GRAPH  *CityGraph // grafo
)
{
   GRAPH_NODE* New;

   int i=0;

   while(*Leafs!=NULL) //finchè lo STACK è vuoto
   {  // alloca nodo
      NewNode(CityGraph,&(CityGraph->MaxAllocNode),i);
      New=CityGraph->StartNode+i;
      // inizializza il nuovo elemento
      New->Node=Pop_STACK(Leafs);
      New->Ark=NULL;
      New->Visited=-1;
      i++;
   }
   CityGraph->TotNodes=i;   // imposta le dimensioni del grafo   
   LinkLOCALS(CityGraph,i); // crea la struttura di collegamenti
}



