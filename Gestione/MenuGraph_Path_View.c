#include "../include/libgraph.h"
#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| Menù per la visualizzazione dell OUTPUT della funzione Path                  |
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
void MenuGraph_Path_View 
(
   GRAPH *Grafo,  //viene passato il GRAFO
   int *Steps,    //array dei nodi visitati               
   int Dim        //numero di passi (=dimensioni Steps)
)
{
   int i;         //indici
   int Exit;      //stato d'uscita
   
   i=0;           //inizializzazioni
   Exit=0;
   
   do
   {
      DispPopup();//Costruisci il Popup
      SetColor(TXT,BKGRND);//setta colorazione
      if(i>0) //se i passi effettuati sono maggiori di uno
         //stampa il nome del nodo
         Gotoxy(10,25),printf("%s",Grafo->StartNode[Steps[i-1]].Node->City);
      if(i<Dim)
         //se i non ha superato la dimensione dell'array
         Gotoxy(14,25),printf("%s",Grafo->StartNode[Steps[i+1]].Node->City);
      SetColor(HTXT,HBKGRND);//colorazione di evidenziamento
      if(i>0)
         Gotoxy(8,38), printf("^");//stampa controllo UP
      Gotoxy(12,25);
      printf("%s",Grafo->StartNode[Steps[i]].Node->City);
      if(i<Dim)
         Gotoxy(16,38), printf("v");//stampa constrollo DOWN

      Gotoxy(5,28);printf("%-4d PASSI EFFETTUATI", Dim);
      TextReset();     
      
      switch(GetKey()) //switch dei controlli direzionali
      {
         case UP:  if(i>0)   //se UP
                        i--; //decrementa e visualizza elementi corrispondeti
                     break;
         case DOWN: if(i<Dim)
                        i++;
                     break;
         case BACKSPACE: Exit=1; //se BACKSPACE, esci
                         break;
      }
   }
   while(!Exit); //fino all'asserimento della FLAG
}
