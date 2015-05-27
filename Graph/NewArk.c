#include "../include/libgraph.h"
/*-----------------------------------------------------------------------------*
| NewArk: Alloca un nuovo nodo di tipo ARK, e collega due nodi                 |
|                                                                              |
|                                                                              |
|                                                                              |
| Data creazione: 24/12/2008                           Autore: Paolo Cittadini |
*-----------------------------------------------------------------------------*/
void NewArk
(
   GRAPH *CityGraph, // grafo di input
   int ID_A,         // id nodo source
   int ID_B          // id nodo destinazione
)
{
   ARK *Current;     //arco temporaneo (per lo scorrimento)
   ARK *New;         //nuovo nodo da aggiungere alla struttura
   //se non stiamo cercando di collegare elementi inesistenti o eliminati
   if(CityGraph->StartNode[ID_A].Node&&CityGraph->StartNode[ID_B].Node)
   {
      //salvataggio della struttura
      Current=CityGraph->StartNode[ID_A].Ark;
      //creazione nuova struttura
      New=Current;
      //scorrimento struttura corrente
      while(Current!=NULL)
      {
         New=Current;
         //aggiunta del nuovo nodo
         Current=Current->NextArk;
      }
      if(!New)
      {
         //allocazione del nodo
         CityGraph->StartNode[ID_A].Ark=(ARK*)malloc(sizeof(ARK));
         //la struttura viene riassegnata
         New=CityGraph->StartNode[ID_A].Ark;
      }
      else
      {
         New->NextArk=(ARK*)malloc(sizeof(ARK));
         New=New->NextArk;
      }
      //inserimento id nodo collegato all'elemento attuale
      New->IDLinkedNode=ID_B;
      //inserimento del Peso (distanga geodetica)
      New->KmDist=GeoDist(CityGraph->StartNode[ID_A].Node->Lat,
                                CityGraph->StartNode[ID_A].Node->Long,
                                CityGraph->StartNode[ID_B].Node->Lat,
                                CityGraph->StartNode[ID_B].Node->Long);
      New->NextArk=NULL;
   }
}
