#include "../include/libgraph.h"
/*-----------------------------------------------------------------------------*
| Function per l'eliminazione di un nodo dal grafo.                            |
| La strategia adottata è quella della memoria resa disponibile in locale,     |
| cioè per l'inserimento di nuovi nodi.                                        |
|                                                                              |
| Data creazione: 04/01/2008                           Autore: Paolo Cittadini |
*-----------------------------------------------------------------------------*/
void EraseNode
(
   GRAPH *CityGraph, //GRAFO
   int ID            //target ID da eliminare
)
{
   int *LinkedNode;  //array contenente gli ID linkati al nodo da eliminare:
                     //servirà per scorrere le rispettive liste ed eliminare il 
                     //link all'id eliminato         
   int Alloc=0;      //contatore elementi nell'array
   int i=0;
   int Nodes;        //variabile d'appoggio 
   ARK  *Swap,*Prec; //archi di SWAP

   LinkedNode=(int*)malloc(sizeof(int));//allocazione array 

   free(CityGraph->StartNode[ID].Node);//free sul nodo da eliminare
   CityGraph->StartNode[ID].Node=NULL; //puntamento a NULL
   (CityGraph->TotNodes)--;            //si decrementa TotNodes
   (CityGraph->MaxAllocNode)++;        //si incrementa il numero di nodi disponibili
   //finchè non finisce lo scorrimento dell'arco
   while(CityGraph->StartNode[ID].Ark!=NULL)
   {
      Alloc++; //si incrementa la dimensione dell'array
      //riallocazione dell'array
      LinkedNode=(int*)realloc(LinkedNode,Alloc*sizeof(int));
      //salvataggio del link
      LinkedNode[i]=CityGraph->StartNode[ID].Ark->IDLinkedNode;
      //si fa puntare la lista a SWAP
      Swap = CityGraph->StartNode[ID].Ark;          //scorrimento lista degli archi
      CityGraph->StartNode[ID].Ark = Swap->NextArk;
      free (Swap);                                  //liberazione archi

      i++;
   }
//PROCEDURA DI RICERCA ED ELIMINAZIONE DEI LINK RESIDUI
//scorrimento dell'array
   for(i=0;i<Alloc;i++)
   {
      Nodes=LinkedNode[i];//NODES = elemento che puntava all'ID eliminato
      Prec=NULL;
      Swap=CityGraph->StartNode[Nodes].Ark;
      //ci salviamo la sua struttura ARK
      //iniziamo lo scorrimento
      while(Swap)
      {
         //se corrisponde al target ID 
         if(Swap->IDLinkedNode==ID)
         {
            if(Prec) //se non è il primo elemento della lista
            {  //estrazione per scorrimento con salvataggio
               Prec->NextArk=Swap->NextArk;
               free(Swap);
               //viene liberata la posizione 
               Swap=Prec->NextArk;
               //ripuntamento della struttura
            }
            else //se l'id è il primo della lista (in testa)
            {
               CityGraph->StartNode[Nodes].Ark=Swap->NextArk;
               free(Swap);
               Swap=CityGraph->StartNode[Nodes].Ark;
            }
         }
         else //non è ancora stato trovato l'ID
         {
            Prec=Swap; //salvataggio
            Swap=Swap->NextArk;//scorrimento
         }   
      }
   }
   free(LinkedNode);//viene liberato l'array degli elementi
}
