#include "../include/libgraph.h"
/*-----------------------------------------------------------------------------*
| Esempio di conversione liste di adiacenza in matrice di adiacenza.           |
|                                                                              |
|                                                                              |
|                                                                              |
| Data creazione: 04/01/2008                           Autore: Paolo Cittadini |
*-----------------------------------------------------------------------------*/
/*[DEPRECATED]*/
void CreateMatrix
(
   GRAPH *CityGraph,  //GRAFO di input con liste di adiacenza
   int ***Matrix      //output del GRAFO come matrice delle adiacenze
)
{
   int i;             //
   ARK *Temp;         // arco temporaneo per lo scorrimento della lista degli archi 
   
   for(i=0;i<CityGraph->TotNodes;i++) // viene allocata la matrice in fuznione di TotNodes
   {
      (*Matrix)[i]=(int*)calloc(CityGraph->TotNodes,sizeof(int));
   }
   for(i=0;i<CityGraph->TotNodes;i++)
   {
      Temp=CityGraph->StartNode[i].Ark;//arco temporaneo da scorrere
      while(Temp!=NULL)
      {
         
         (*Matrix)[i][Temp->IDLinkedNode]=1;// collegamento i-->ID
         (*Matrix)[Temp->IDLinkedNode][i]=1;// collegamento ID<--i
         (*Matrix)[i][i]=2;                 // collegamento riflessivo
         Temp=Temp->NextArk;                // scorrimento arco
      }
     
   }
}
   
      
