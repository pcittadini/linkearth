#include "../include/libgraph.h"
/*-----------------------------------------------------------------------------*
| Function per la creazione di una copertura long distance sul grafo.          |
|                                                                              |
|                                                                              |
|                                                                              |
| Data creazione: 04/01/2008                           Autore: Paolo Cittadini |
*-----------------------------------------------------------------------------*/

void LinkLD
(
   GRAPH *CityGraph, //grafo di input
   int FarNodes      //% di nodi da linkare con long distance link
)
{
   int i; //indici
   int j;
   int Step; //intervallo fra i link
   //lo step viene calcolato in base al numero di nodi
   Step=(CityGraph->TotNodes)/FarNodes;

   j=0;
   //il ciclo gestisce la creazione di nuovi archi
   for(i=0;i<=(CityGraph->TotNodes)/2;i+=Step)
   {
      //finchè non viene trovato un nodo eliminato
      while(!CityGraph->StartNode[j].Node)
         j++;
      //creazione archi
      NewArk(CityGraph,j,((CityGraph->TotNodes/2)+j)%CityGraph->TotNodes);
      NewArk(CityGraph,((CityGraph->TotNodes/2)+j)%CityGraph->TotNodes,j);
      //j viene incrementato in base allo step
      j+=Step;
   }
}
   
