#include "graph.h"
#include "../lib/stack/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*-----------------------------------------------------------------------------*
| Header contenente i prototipi delle funzioni per la gestione del GRAFO       |
|                                                                              |
|                                                                              |
| Data creazione: 22/12/2008            Autore: Cittadini Paolo e Arcadio Ciro |
*-----------------------------------------------------------------------------*/

//path: ./Graph


/*[3x10]*/void NewArk       (GRAPH *CityGraph, int ID_A, int ID_B);
/*[3x11]*/void NewNode      (GRAPH *CityGraph, int *MaxAllocNode, int Size);
/*[3x12]*/void StackToGraph (STACK **Leafs,    GRAPH *CityGraph);
/*[3x13]*/void LinkLOCALS   (GRAPH *CityGraph, int TotNode);
/*[3x14]*/int  *SearchNode  (GRAPH CityGraph,  char *Key, int *IDAlloc);
/*[3x15]*/void FreeGraph    (GRAPH *Graph);
/*[3x16]*/void EraseNode    (GRAPH *CityGraph, int ID);
/*[3x17]*/int* Path         (GRAPH *Grafo,int **Line,int Dim,int *Counter,int ID);
/*[3x18]*/void CreateMatrix (GRAPH *CityGraph, int ***Matrix);
/*[3x19]*/void LinkLD       (GRAPH *CityGraph, int FarNodes);
/*[3x20]*/void NewHUB       (GRAPH *CityGraph, int ID, int LinkRank);
/*[3x21]*/float HUBRank     (GRAPH *CityGraph, int ID);
/*[3x22]*/double GeoDist    (double LatA, double LonA, double LatB, double LonB);
