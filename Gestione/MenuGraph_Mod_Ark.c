#include "../include/libgraph.h"
#include "../lib/platform/platform.h"
#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| Menù per la creazione di un nuovo arco                                       |
|                                                                              |
|            Tramite un indice, permette l'interazione e la selezione di       || una lista di funzioni con un semplice input da tastiera.                     |
|                                                                              |
|            ENTER:     accetta/avanti                                         |
|            BACKSPACE: annulla/indietro                                       |
|            UP:        sposta cursore su                                      |
|            DOWN:      sposta cursore giu'                                    |
|            LEFT:      sposta cursore a sinistra                              |
|            RIGHT:     sposta cursore a destra                                |
|                                                                              |
| Ultima modifica: 28/01/2009                           Autore: Paolo Cittadini|
*-----------------------------------------------------------------------------*/
void MenuGraph_Mod_Ark
(
   GRAPH *Grafo // grafo di input
)
{
   int i,j;     //indici
   int IDA,IDB; //id da collegare
   int TmpID;   //
   char *String;//buffer di lettura
   int Exit;    //flag d'uscita
   int c;
   
   i=0;         //inizializzazioni
   j=0;
   while(!Grafo->StartNode[j].Node)//finchè non è NULL
     j++;
   IDA=j;//indici di gestione scorrimento nel menù
   IDB=j;
   j=IDA;
   TmpID=0;
   String=NULL;
   Exit=0;
   
   do    //gestione menù
   {
      if(i<4)
         IDA=j;
      else
         IDB=j;
      
      DispPopup();// costruisci il popup
      SetColor(TXT,BKGRND); //setta colorazione
      //setta valori in base allo scorrimento degli indici
      Gotoxy(11,30);printf("%s",Grafo->StartNode[IDA].Node->City);
      Gotoxy(17,30);printf("%s",Grafo->StartNode[IDB].Node->City);
      TextReset();
      //reset del layout
      DispForeground(MenuGRAPH_PATH,i);
      //disegna il foreground
      if(i==0||i==6)//controlli sulla stampa (CONTROLLI SUI MARGINI)
         Gotoxy(i+9,30);
      
      c=GetKey(); // switch di GetKey
      switch(c)   //
      {
         case UP: if(i>0)  // caso UP
                  {
                    if(i!=6)
                       i-=2;
                    else
                       i-=4, j=IDA;
                  }
                  break;
         case DOWN: if(i<8)// caso DOWN
                    {
                       if(i!=2)
                          i+=2;
                       else
                          i+=4, j=IDB;
                    }
                    break;
         case LEFT: if(i==2||i==8) //caso LEFT
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
         case ENTER: NewArk(Grafo,IDA,IDB); //caso ENTER viene effettuato il link
                     NewArk(Grafo,IDB,IDA);
                     Exit=1;  //uscita
                     break;
         case BACKSPACE: Exit=1; //uscita con BACKSPACE
                         break;
         default: if(i==0||i==6) //controlli sui margini
                  {
                     Gotoxy(i+9,30);
                     String=GetNumInLine(c,i+3);//controlli sul BUFFER
                     TmpID=atoi(String);//conversione
                     free(String);//liberazione memoria
                     if(TmpID>=0&&TmpID<=(Grafo->TotNodes+Grafo->MaxAllocNode))
                        if(Grafo->StartNode[TmpID].Node)
                           j=TmpID;
                  }
                  break;
      }
   }
  while(!Exit);//finchè non è asserita la flag d'uscita
}
