#include "../include/libgraph.h"
#include "../lib/platform/platform.h"
#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| MenuGraph_Mod_Hub: struttura per menu interattivo                            |
|                                                                              |
|            Tramite un indice, permette l'interazione e la selezione di       || una lista di funzioni con un semplice input da tastiera.                     |
| Permette di trasformare uno o più nodi del grafo in un HUB con un numero di  |
| archi definito dall'utente. Prevede anche un campo di ricerca per nome.      |
|                                                                              |
|            ENTER:     accetta/avanti                                         |
|            BACKSPACE: annulla/indietro                                       |
|            UP:        sposta cursore su                                      |
|            DOWN:      sposta cursore giu'                                    |
|            LEFT:      sposta cursore a sinistra                              |
|            RIGHT:     sposta cursore a destra                                |
|                                                                              |
| Data creazione: 02/02/2009                              Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/

void MenuGraph_Mod_Hub
(
   GRAPH *Grafo
)
{
   int i,j,t,Exit;   // Exit = Stato d'uscita [0=continua; 1=esci]
   int ID;           // ID del nodo da trasformare in HUB
   int c;            // ASCII del carattere di input
   int Rank;         // Rank dell'HUB (quantità di links)
   char *String;     // buffer di lettura
   int *StoredID;    // contiene l'output della ricerca [id]
   int TotStoredID;  // dimensioni di StoredID
   
   String=NULL;
   StoredID=NULL;

   Exit=0;
   TotStoredID=0;
   ID=0;
   while(!Grafo->StartNode[ID].Node) // ignora campi vuoti
      ID++;
   j=ID;
   i=2;
   t=0;
   Rank=(9%(Grafo->TotNodes))+1; // imposta una soglia minima di archi
   do
   {
      DispPopup(); // stampa un popup vuoto
      DispForeground(MenuGRAPH_MOD_H,i); // stampa info di foreground
      
      SetColor(TXT,BKGRND);
      // stampa info aggiuntive
      Gotoxy(18,30);
      if(TotStoredID)
         ID=StoredID[0], j=ID;
      printf("%d",ID);
      for(t=1;t<TotStoredID;t++)
         printf(", %d",StoredID[t]);
      
      Gotoxy(10,31);
      printf("%s",Grafo->StartNode[j].Node->City);
      Gotoxy(12,31);
      printf("%d",Rank);
      if(i!=2)
         Gotoxy(22,76);
      else
         Gotoxy(i+6,30);
         
      TextReset();
          
      c=GetKey(); // ottiene l'input da tastiera
      switch(c)
      {
       case UP        : if(i>2)
                          i-=2;
                        break;
       case DOWN      : if(i<6)
                          i+=2;
                        break;
       case BACKSPACE : Exit=1; 
                        break;
                          
       case ENTER     : NewHUB(Grafo,ID,Rank); // trasforma tutti i nodi
                        if(TotStoredID)        // selezionati, in HUB
                           for(t=1;t<TotStoredID;t++)
                               NewHUB(Grafo,StoredID[t],Rank);
                        Exit=1;
                        break;
                        
       case LEFT      : switch(i)
                        {
                           case 4: do
                                   {
                                    if(j>0)
                                       j--;
                                    else
                                       j=((Grafo->TotNodes+Grafo->MaxAllocNode)-1);
                                   }
                                   while(!Grafo->StartNode[j].Node);
                                   if(StoredID)
                                      free(StoredID), StoredID=NULL;
                                   TotStoredID=0;
                                   ID=j;
                                   break;
                           case 6: if(Rank>(9%(Grafo->TotNodes))+1)
                                      Rank--;
                                   else
                                       Rank=(Grafo->TotNodes)-1;
                                   break;
                        }
                        break;
                        
       case RIGHT     : switch(i)
                        {
                           case 4: do
                                   {
                                      if(j<((Grafo->TotNodes)-1))
                                         j++;
                                      else
                                         j=0;
                                   }
                                   while(!Grafo->StartNode[j].Node);
                                   if(StoredID)
                                      free(StoredID), StoredID=NULL;
                                   TotStoredID=0;
                                   ID=j;
                                   break;
                           case 6: if(Rank<(Grafo->TotNodes)-1)
                                      Rank++;
                                   else
                                       Rank=(9%(Grafo->TotNodes))+1;
                                   break;
                        }
                        break;
        
       default        : Gotoxy(i+6,30);
                        if(i==2)
                        { 
                           String=GetchInLine(c,i);
                           if(StoredID)
                              free(StoredID), StoredID=NULL;
                           TotStoredID=0;
                           // ricerca per nome
                           StoredID=SearchNode(*Grafo,String,&TotStoredID);
                           free(String);
                         }
                         break;
        }
   }while(!Exit);  //Finchè non è asserita Exit
   if(StoredID)
      free(StoredID);
}
