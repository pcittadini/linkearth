#include "../include/libgraph.h"
#include "../lib/platform/platform.h"
#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| MenuGraph_Path: gestisce il menu di ricerca percorsi in un grafo             |
|                                                                              |
|            Tramite un indice, permette l'interazione e la selezione di       || una lista di funzioni con un semplice input da tastiera.                     |
| Permette di selezionare un nodo di partenza e uno di arrivo per la function  |
| path. E' possibile selezionare i nodi per id. Al termine dell'esecuzione di  |
| Path, avvia un menu di visualizzazione dei risultati ottenuti.               |
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
void MenuGraph_Path
(
   GRAPH *Grafo
)
{
   int i,j;
   int IDA,IDB;  // IDA nodo di partenza; IDB nodi di destinazione
   int TmpID;    // ID ottenuto da tastiera
   char *String; // stringa di supporto per gli input da tastiera
   int *Steps;   // contiene gli id degli elementi attraversati durante
                 // l'esecuzione di path
   int Counter;  // numero di passi effettuati da path
   int Exit;     // condizione di uscita [0=continua; 1=esci]
   int c;        // ASCII del carattere di input
   
   i=0;
   j=0;
   while(!Grafo->StartNode[j].Node) // ignora campi vuoti nel grafo
     j++;
   IDA=j;
   IDB=j;
   j=IDA;
   TmpID=0;
   String=NULL;
   Counter=0;
   Steps=malloc(sizeof(int));
   Exit=0;
   
   do
   {
      if(i<4)
         IDA=j;
      else
         IDB=j;    
      
      DispPopup(); // stampa un popup vuoto
      // stampa info aggiuntive
      SetColor(TXT,BKGRND);
      Gotoxy(11,30);printf("%s",Grafo->StartNode[IDA].Node->City);
      Gotoxy(17,30);printf("%s",Grafo->StartNode[IDB].Node->City);
      TextReset();
      // stampa info in foreground
      DispForeground(MenuGRAPH_PATH,i);
      if(i==0||i==6)
         Gotoxy(i+9,30);
      
      c=GetKey();
      switch(c)
      {
         case UP: if(i>0)
                  {
                    if(i!=6)
                       i-=2;
                    else
                       i-=4, j=IDA;
                  }
                  break;
         case DOWN: if(i<8)
                    {
                       if(i!=2)
                          i+=2;
                       else
                          i+=4, j=IDB;
                    }
                    break;
         case LEFT: if(i==2||i==8)
                    {
                       do
                       {
                          if(j>0)
                             j--;
                          else
                             j=((Grafo->TotNodes+Grafo->MaxAllocNode)-1);
                       }
                       while(!Grafo->StartNode[j].Node); 
                    }
                    break;
         case RIGHT: if(i==2||i==8)
                     {
                        do
                        {
                           if(j<((Grafo->TotNodes+Grafo->MaxAllocNode)-1))
                              j++;
                           else
                              j=0;
                        }
                        while(!Grafo->StartNode[j].Node);
                     }
                     break;
         case ENTER: // esegue la ricerca di un percorso tra i nodi selezionati
                     Steps[0]=IDA;
                     Steps=Path(Grafo,&Steps,1,&Counter,IDB);
                     // visualizza l'esito di path
                     MenuGraph_Path_View(Grafo,Steps,Counter-1);
                     Counter=0;
                     break;
         case BACKSPACE: Exit=1;
                         break;
         default: if(i==0||i==6)
                  {
                     Gotoxy(i+9,30);
                     // effettua la ricerca per id
                     String=GetNumInLine(c,i+3);
                     TmpID=atoi(String);
                     free(String);
                     if(TmpID>=0&&TmpID<=(Grafo->TotNodes+Grafo->MaxAllocNode))
                        if(Grafo->StartNode[TmpID].Node)
                           j=TmpID;
                  }
                  break;
      }
   }
   while(!Exit);
   free(Steps);
}
