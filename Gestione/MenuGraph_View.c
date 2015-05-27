#include "../include/libgraph.h"
#include "../lib/platform/platform.h"
#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| MenuGraph_View: gestisce il menu di visualizzazione di un grafo.             |
|                                                                              |
|            Tramite un indice, permette l'interazione e la selezione di       || una lista di funzioni con un semplice input da tastiera.                     |
| Visualizza il grafo nodo per nodo. E' possibile scorrere velocemente il      |
| grafo tramite le frecce "LEFT" e "RIGHT", che attraversano rispettivamente   |
| il secondo ed il primo arco della lista. Una lista laterale consente di      |
| visualizzare e selezionare (scorrendo con i tasti "UP" e "DOWN") tutti gli   |
| archi del nodo in esame. Al centro dello schermo vengono visualizzate volta  |
| per volta, le info del nodo attuale e quelle del nodo puntato dall'arco      |
| selezionato, con relativa distanza in km (peso dell'arco). Il tasto ENTER    |
| sposta la visualizzazione sul nodo puntato dall'arco selezionato.            |
|                                                                              |
|            ENTER:     accetta/avanti                                         |
|            BACKSPACE: annulla/indietro                                       |
|            UP:        sposta cursore su                                      |
|            DOWN:      sposta cursore giu'                                    |
|            LEFT:      sposta cursore a sinistra                              |
|            RIGHT:     sposta cursore a destra                                |
|                                                                              |
| Ultima modifica: 02/02/2009                             Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/
void MenuGraph_View
(
   GRAPH *Grafo
)
{
   int x;        // indice di riga
   int y;        // indice di colonna
   int Exit;     // condizione di uscita [0=continua; 1=esci]
   int Current;  // id del nodo in esame
   int ArkNum;   // numero degli archi del nodo in esame
   ARK *Tmp;     // puntatore all'arco
   
   ArkNum=0;
   x=0;
   while(!Grafo->StartNode[x].Node) // ignora campi vuoti nel grafo
      x++; 
   y=0;
   Exit=0;
   Current=-1;
   
   do
   {
      Tmp=Grafo->StartNode[x].Ark; // punta alla lista di archi del nodo in esame
      
      if(Current!=x)       // se il nodo selezionato è diverso da quello precedente
      {                    // ricalcola il numero di archi
         ArkNum=0;
         while(Tmp)
         {
            Tmp=Tmp->NextArk;
            ArkNum++;
         }
         Current=x;
      }
      
      DispBackground();
      DispGraph(Grafo,x,y,ArkNum); // visualizza info sul grafo
      
      Tmp=Grafo->StartNode[x].Ark;
      
      switch(GetKey())
      {
         case LEFT   : if(Tmp)
                        if(Tmp->NextArk)
                           x=Tmp->NextArk->IDLinkedNode, y=0;
                       break;
         case RIGHT  : if(Tmp)
                           x=Tmp->IDLinkedNode, y=0;
                       break;
                                              
         case UP     : if(y>0)
                        y--;
                       break;
         case DOWN   : if(y<(ArkNum-1))
                        y++;
                       break;
         case ENTER  : Tmp=Grafo->StartNode[x].Ark;    // va al nodo selezionato 
                       for(ArkNum=0;ArkNum<y;ArkNum++)
                          Tmp=Tmp->NextArk;
                       x=Tmp->IDLinkedNode;
                       y=0;
                       break;
         case BACKSPACE:Exit=1;
                        break;
      }
      
   }while(!Exit);
}
