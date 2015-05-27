#include "../include/libgraph.h"
/*-----------------------------------------------------------------------------*
| NewHub: trasforma un nodo del grafo in un HUB collegandolo ad un numero      |
|         di elementi dato, distanti fra loro di un numero pari al totale dei  |
|         nodi, fratto il rank di collegamento.                                |
|                                                                              |
| Data creazione: 29/01/2009                              Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/
void NewHUB
(
   GRAPH *CityGraph,
   int ID,           // id del nodo HUB
   int LinkRank      // tasso di collegamento dell'HUB
)
{
   int Step;         // distanza tra i nodi da collegare
   int i;

   Step=(CityGraph->TotNodes)/LinkRank; // calcola lo step
   for(i=0;i<(CityGraph->TotNodes+CityGraph->MaxAllocNode);i+=Step)
      if(CityGraph->StartNode[i].Node) // se è presente l'elemento
         if(i!=ID)
         {
            NewArk(CityGraph,ID,i);    // crea i nodi
            NewArk(CityGraph,i,ID); 
         }
}

