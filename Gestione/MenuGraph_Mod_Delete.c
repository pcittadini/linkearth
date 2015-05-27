#include "../include/libgraph.h"
#include "../lib/platform/platform.h"
#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| MenuGraph_Mod_Delete: struttura per menu interattivo                         |
|                                                                              |
|            Tramite un indice, permette l'interazione e la selezione di       || una lista di funzioni con un semplice input da tastiera.                     |
| Consente l'eliminazione di un elemento o una lista di elementi del grafo,    |
| selezionati tramite ricerca per nome o scorrimento.                          |
|                                                                              |
|            ENTER:     accetta/avanti                                         |
|            BACKSPACE: annulla/indietro                                       |
|            UP:        sposta cursore su                                      |
|            DOWN:      sposta cursore giu'                                    |
|            LEFT:      sposta cursore a sinistra                              |
|            RIGHT:     sposta cursore a destra                                |
|                                                                              |
| Data creazione: 29/01/2009                              Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/

void MenuGraph_Mod_Delete
(
   GRAPH *Grafo
)
{
   int i,j,t,Exit;   // Exit = Stato d'uscita [0=continua; 1=esci]
   int ID;           // id del nodo da eliminare
   int c;            // ASCII del carattere di selezione
   char *String;     // puntatore alla stringa di supporto
   int *StoredID;    // array contenente gli id restituiti dalla ricerca
   int TotStoredID;  // dimensioni di StoredID
   
   String=NULL;
   StoredID=NULL;

   Exit=0;
   TotStoredID=0;
   ID=0;
   while(!Grafo->StartNode[ID].Node) // ignora eventuali spazi vuoti
      ID++;
   j=ID;
   i=2;
   
   do
   {
      DispPopup();
      DispForeground(MenuGRAPH_MOD_D,i);
      
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

      if(i!=2)
      {
         SetColor(HTXT,HBKGRND);
         Gotoxy(i+6,30); printf("<");
         Gotoxy(i+6,60); printf(">");
         SetColor(TXT,BKGRND);
         Gotoxy(22,76);
      }
      else
         Gotoxy(i+6,30);
         
      TextReset();
          
      c=GetKey();  // ottiene l'input da tastiera
      switch(c)
      {
       case UP        : if(i>2)
                          i-=2;
                        break;
       case DOWN      : if(i<4)
                          i+=2;
                        break;
       case BACKSPACE : Exit=1; 
                        break;
                          
       case ENTER     : EraseNode(Grafo,ID); // Elimina tutti gli elementi
                        if(TotStoredID)      // selezionati 
                           for(t=1;t<TotStoredID;t++)
                               EraseNode(Grafo,StoredID[t]);
                        Exit=1;
                        break;
                        
       case LEFT      : if(i==4)
                        {
                           do
                           {
                              if(j>0)
                                 j--;
                              else
                                 j=((Grafo->TotNodes+Grafo->MaxAllocNode)-1);
                           }
                           while(!Grafo->StartNode[j].Node);
                           if(TotStoredID)
                              free(StoredID), StoredID=NULL;
                           TotStoredID=0;
                           ID=j;
                        }
                        break;
                        
       case RIGHT     : if(i==4)
                        {
                           do
                           {
                              if(j<((Grafo->TotNodes+Grafo->MaxAllocNode)-1))
                                 j++;
                              else
                                 j=0;
                           }
                           while(!Grafo->StartNode[j].Node);
                           if(TotStoredID)
                              free(StoredID), StoredID=NULL;
                           TotStoredID=0;
                           ID=j;
                        }
                        break;
        
       default        : Gotoxy(i+6,30);
                        if(i==2)
                        { 
                           String=GetchInLine(c,i);
                           if(TotStoredID)
                              free(StoredID), StoredID=NULL;
                           TotStoredID=0;
                           // ricerca per nome
                           StoredID=SearchNode(*Grafo,String,&TotStoredID);
                           free(String);
                         }
                         break;
        }
   }while(!Exit);  // Finchè non è asserita Exit
   if(StoredID)
      free(StoredID);
}
