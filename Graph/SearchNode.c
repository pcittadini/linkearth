#include "../include/libgraph.h"
/*-----------------------------------------------------------------------------*
| Function per la ricerca di un nodo nella struttura grafo                     |
|                                                                              |
|                                                                              |
|                                                                              |
| Data creazione: 04/01/2008                           Autore: Paolo Cittadini |
*-----------------------------------------------------------------------------*/
int* SearchNode 
//la funzione restituisce un array contenente tutti i risultati trovati
(
   GRAPH CityGraph,//grafo di input
   char *Key,      //chiave di ricerca
   int *IDAlloc    //dimensioni dell'array di output (numero di elementi trovati)
)
{
   int *ID;        
   int i=0;
   int j=0;
   int Alloc=0;
   ID=(int*)malloc(sizeof(int));//allocazione 

   while(i<(CityGraph.TotNodes+CityGraph.MaxAllocNode))
   {
      if(CityGraph.StartNode[i].Node)
      //controllo elementi eliminati o inesistenti
         if(!strcasecmp(CityGraph.StartNode[i].Node->City,Key))
         {
            Alloc++;
            ID=(int*)realloc(ID,(1+Alloc)*sizeof(int));
            ID[j]=i;
            j++;
         }
      i++;
   }
   *IDAlloc=Alloc;
   return ID;
}

