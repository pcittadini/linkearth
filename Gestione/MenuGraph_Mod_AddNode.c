#include "../include/libgraph.h"
#include "../lib/platform/platform.h"
#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| MenuGraph_Mod_AddNode: gestisce il menu di inserimento nuovo nodo            |
|                                                                              |
|            Tramite un indice, permette l'interazione e la selezione di       || una lista di funzioni con un semplice input da tastiera. Prevede stringhe    |
| di input da tastiera, effettua una ricerca per nome nel grafo e aggiunge     |
| un nuovo nodo con un numero di archi definito dall'utente.                   |
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

void MenuGraph_Mod_AddNode
(
   GRAPH *Grafo 
)
{
   int i,j,t,Exit;   // Exit = Stato d'uscita [0=continua; 1=esci]
   int id;
   int c;            // ASCII del carattere di selezione
   char *String;     // stringa di supporto
   int *StoredID;    // contiene eventuali id di destinazione multipli
   int TotStoredID;  // dimensioni di StoredID
   int LinkTo;       // ID di destinazione (il nuovo elemento sara' collegato
                     // a questo)
   TREE *NewN;       // NODO da far puntare alla struttura
   
   String=NULL;      //inizializzazioni
   StoredID=NULL;
   NewN=(TREE*)calloc(1,sizeof(TREE));     //alloca il nuovo nodo

   Exit=0;
   TotStoredID=0;
   LinkTo=0;
   while(!Grafo->StartNode[LinkTo].Node) // ignora gli spazi vuoti allocati in 
      LinkTo++;                          // in memoria
   j=LinkTo;
   i=0;
   t=0;
   id=0;
   
   // cerca uno spazio vuoto nel grafo
   if(Grafo->MaxAllocNode)
      while(Grafo->StartNode[id].Node)
            id++;
   else
      id=Grafo->TotNodes;
   NewNode(Grafo,&(Grafo->MaxAllocNode),Grafo->TotNodes);
   
   do
   {  // mostra un POPUP
      DispPopup();
      //disegna il fg per il menù richiesto
      DispForeground(MenuGRAPH_MOD_A,i);
      //stampa info aggiuntive
      SetColor(TXT,BKGRND);
      Gotoxy(6,30);
      printf("%s",NewN->City);
      Gotoxy(8,30);
      printf("%d",NewN->Region);
      Gotoxy(10,30);
      printf("%f",NewN->Lat);
      Gotoxy(12,30);
      printf("%f",NewN->Long);

      Gotoxy(18,30);
      if(TotStoredID)
         LinkTo=StoredID[0], j=LinkTo;
      printf("%d",LinkTo);
      for(t=1;t<TotStoredID;t++)
         printf(", %d",StoredID[t]);
      
      Gotoxy(16,31);
      printf("%s",Grafo->StartNode[j].Node->City);
      if(i==10)
      {
         SetColor(HTXT,HBKGRND);
         printf(">");
         Gotoxy(16,30); printf("<");
         SetColor(TXT,BKGRND);
         Gotoxy(22,76);
      }
      else
         Gotoxy(i+6,30);
         
      TextReset();     
      c=GetKey();  //GetKey
      switch(c)    //switch dei valori di c
      {
       case UP        : if(i>0)    //tasto UP
                          i-=2;
                        break;
       case DOWN      : if(i<10)   //tasto DOWN
                          i+=2;
                        break;
       case BACKSPACE : free(NewN); //BACKSPACE per uscire
                        Exit=1; 
                        break;
                          
       case ENTER     : Grafo->StartNode[id].Node=NewN;// ENTER per inserire
                        (Grafo->TotNodes)++;           // aggiorna le dimensioni
                                                       // del grafo
                        NewArk(Grafo,LinkTo,id);       // crea gli archi dal 
                        NewArk(Grafo,id,LinkTo);       // nuovo nodo a tutti i
                        if(TotStoredID)                // nodi di destinazione
                           for(t=1;t<TotStoredID;t++)
                              NewArk(Grafo,id,StoredID[t]);
                        Exit=1;
                        break;
                        
       case LEFT      : if(i==10)
                        {
                           do
                           {
                              if(j>0)
                                 j--;
                              else
                                 j=((Grafo->TotNodes+Grafo->MaxAllocNode)-1);
                              if(TotStoredID)
                                 free(StoredID), StoredID=NULL; 
                           }
                           while(!Grafo->StartNode[j].Node);
                           TotStoredID=0;
                           LinkTo=j;
                        }
                        break;
                        
       case RIGHT     : if(i==10)
                        {
                           do
                           {
                              if(j<((Grafo->TotNodes+Grafo->MaxAllocNode)-1))
                                 j++;
                              else
                                 j=0;
                              if(TotStoredID)
                                 free(StoredID), StoredID=NULL;
                           }
                           while(!Grafo->StartNode[j].Node);
                           TotStoredID=0;
                           LinkTo=j;
                        }
                        break;
        
       default        : Gotoxy(i+6,30);
                         switch(i)
                         {
                          case 0: String=GetchInLine(c,i); // ottiene la stringa
                                  strcpy(NewN->City,String); // di input
                                  free(String); //liberazione buffer di lettura                         
                                  i+=2;
                                  break;
                          case 2: String=GetNumInLine(c,i);
                                  NewN->Region=atoi(String);//conversione
                                  free(String);//liberazione
                                  i+=2;
                                  break;
                          case 4: String=GetchInLine(c,i);
                                  NewN->Lat=atof(String);
                                  free(String); 
                                  i+=2;
                                  break;
                          case 6: String=GetchInLine(c,i);
                                  NewN->Long=atof(String);
                                  free(String); 
                                  i+=2;
                                  break;
                          case 8: String=GetchInLine(c,i);
                                  if(TotStoredID)
                                    free(StoredID), StoredID=NULL;
                                  TotStoredID=0;
                                  StoredID=SearchNode(*Grafo,String,&TotStoredID);
                                  free(String);
                         }
                         break;
        }
   }while(!Exit);  //Finchè non è asserita Exit
   if(StoredID)
      free(StoredID);
}
