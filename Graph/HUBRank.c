#include "../include/libgraph.h"
/*-----------------------------------------------------------------------------*
| Criterio per la scelta degli HUB in modo pseudo -casuale [deprecated]        |                                        
|                                                                              |
|                                                                              |
|                                                                              |
| Data creazione: 04/01/2008                           Autore: Paolo Cittadini |
*-----------------------------------------------------------------------------*/
float HUBRank
(
   GRAPH *CityGraph,
   int ID
)
{
   int i;
   double GeoDistSum;
   
   for (i=0;i<CityGraph->TotNodes;i++)
   {
      GeoDistSum+=GeoDist(
                           CityGraph->StartNode[ID].Node->Lat,
                           CityGraph->StartNode[ID].Node->Long,
                           CityGraph->StartNode[i].Node->Lat,
                           CityGraph->StartNode[i].Node->Long);
   }
   
   return (GeoDistSum)/i;
}

