#include "../include/libgraph.h"
/*-----------------------------------------------------------------------------*
| Function per la creazione dei link di tipo locals iniziali.                  |
|                                                                              |
| Data creazione: 01/01/2008                           Autore: Paolo Cittadini |
*-----------------------------------------------------------------------------*/
void LinkLOCALS
(
   GRAPH *CityGraph, //accetta in input il grafo
   int TotNode       //nodi del grafo in totale
)
{
   int i;
   int id;
   //in un ciclo ogni elemento viene collegato (in ordine di allocazione), al suo
   //successore e predecessore.
   for(i=0;i<TotNode;i++)
   {
         
         id=(i+1)%TotNode;//l'operazione in modulo totnode ci garantisce il link
                          //del primo elemento con l'ultimo, e viceversa.
         NewArk(CityGraph,i,id);
         if(!i)
            id=TotNode-1;
         else
            id=i-1;
         NewArk(CityGraph,i,id);
   }
}
      
