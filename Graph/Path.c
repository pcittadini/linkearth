#include "../include/libgraph.h"
#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| Path: ricerca il percorso minimo tra due nodi in un grafo.                   |
|                                                                              |
|       Percorre il grafo costruendo un albero n-ario di ricerca. Ogni livello |
| dell'albero e' costituito dagli id dei nodi puntati dagli archi degli        |
| elementi del livello precedente. L'id del nodo di partenza costituisce il    |
| root dell'albero di ricerca. La function analizza gli archi degli elementi   |
| di ogni livello e si interrompe quando viene raggiunto il nodo di arrivo.    |
|                                                                              |
|                                                                              |
|         8--P--1__2   8__P__1--2   8__P__1__2     liv.1       [P]             |
|         |  :     |   :  |     |   |  |     :                 /|\             |
|         7__9     3   7--9     3   7  9     3     liv.2      1(9)8            |
|         |  |     |   |  :     |   :  |     |               /  |  \           |
|         6__5__A__4   6__5__A__4   6--5-(A)_4     liv.3    2  (5)  7          |
|                                                          /    |    \         |
|                                                  liv.4  3    [A]    6        |
|                                                                              |
|      __ arco da visitare       P nodo di partenza                            |
|      -- arco visitato          A nodo di arrivo                              |
|                                                                              |
|                                                                              |
| Data creazione: 28/11/2008                              Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/
int* Path
(
   GRAPH *Grafo,     // Struttura Grafo
   int **Line,       // contiene gli ID dei nodi da analizzare al passo corrente
                     // al primo passo è costituito dal solo ID di partenza
   int Dim,          // dimensioni dell'array Line
   int *Counter,     // numero di passi eseguiti
   int ID            // ID di arrivo
)
{
   int i,j;
   int Trovato;  // Flag di segnalazione [0 = ID non ancora trovato]
                 //                      [1 = ID trovato]  
   int Actual;   // contiene il numero attuale di passi eseguiti
   int *NewLine; // contiene gli archi dei nodi dell'attuale livello
   ARK *Tmp;     // Arco di supporto per lo scorrimento delle liste di adiacenza
   
   Trovato=0;
   Actual=*Counter; // Actual viene inizializzato all'attuale numero di passi
                    // eseguiti
   (*Counter)++;    // Counter viene aggiornato al passo corrente
   i=0; j=0;
   
   NewLine=calloc(BATCH_NODE,sizeof(int));
   
///////////////////////////BLOCCO ITERATIVO/////////////////////////////////////
   
   do
   {
      Tmp=Grafo->StartNode[(*Line)[i]].Ark; // Tmp punta al nodo 'i' di Line
      do
      {
         if(Tmp->IDLinkedNode!=ID)       // se non è stato raggiunto l'ID
         {
            if(Grafo->StartNode[Tmp->IDLinkedNode].Visited<0)
            // conserva solo gli archi che puntano a nodi non ancora visitati
            {
               j++;
               if(j%BATCH_NODE>=BATCH_NODE-1)
                  NewLine=realloc(NewLine,(j+BATCH_NODE)*sizeof(int));
               NewLine[j-1]=Tmp->IDLinkedNode;
               Grafo->StartNode[Tmp->IDLinkedNode].Visited=(*Line)[i];
            }
            Tmp=Tmp->NextArk;
         }
         else
         {
            Trovato=1;     // ID trovato
            Grafo->StartNode[Tmp->IDLinkedNode].Visited=(*Line)[i];
         }
      }
      while(!Trovato&&Tmp);// esegue finchè non viene asserita la flag e non
                           // è stata raggiunta la fine della lista di adiacenze
      i++;
   }
   while(!Trovato&&i<Dim); // esegue finchè non viene raggiunto l'ID di arrivo e
                           // non vengono superate le dimensioni dell'array Line
   free(*Line); 
//////////////////////////BLOCCO RICORSIVO//////////////////////////////////////                           
   
   if(!Trovato)
   {
      // chiama ricorsivamente la function per analizzare il nuovo livello
      // dell'albero
      *Line=Path(Grafo,&NewLine,j,Counter,ID);
      // al termine aggiorna l'array di output inserendo l'id del passo attuale
      (*Line)[Actual]=Grafo->StartNode[(*Line)[Actual+1]].Visited;
   }
   else
   {
      // alloca l'array di output e immagazina i passi attuali
      *Line=calloc(++(*Counter),sizeof(int));
      (*Line)[Actual]=Grafo->StartNode[Tmp->IDLinkedNode].Visited;
      (*Line)[Actual+1]=ID;
      // libera la memoria finora allocata per gli id errati
      free(NewLine);
   }
   
/////////////////////////RIPRISTINO CONDIZIONI DI PARTENZA//////////////////////
   if(!Actual) // al termine della ricorsione ripristina le flag Visited
      for(i=0;i<Grafo->TotNodes+Grafo->MaxAllocNode;i++)
         Grafo->StartNode[i].Visited=-1;   
   
   return (*Line);
}
