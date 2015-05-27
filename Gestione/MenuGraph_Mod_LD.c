#include "../include/libgraph.h"
#include "../lib/platform/platform.h"
#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| Menù per l'inserimento di nodi Long Distance (LD)                            |
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
void MenuGraph_Mod_LD
(
   GRAPH *Grafo  //grafo passato alla funzione
)
{ 
   int i;        //flag e indici
   int Exit;
   int Percent;  //percentuale di copertura
     
   i=5;          //posizionamento     
   Exit=0;       //flag di "stato d'uscita"
   Percent=0;    // 
   
   do
   {
      DispPopup();//Display del POPUP
      SetColor(TXT,BKGRND);//settaggio colorazione
      Gotoxy(8,25);
      printf("nodi presenti:%16d", Grafo->TotNodes);
      Gotoxy(10,25);
      printf("inserisci la percentuale di LD");
      Gotoxy(12,36);
      printf("%3d%c",i,37);
      SetColor(HTXT,HBKGRND);
      if(i>5)
         Gotoxy(12,35),printf("<");
      if(i<100)
         Gotoxy(12,40),printf(">");
      TextReset(); //reset del layout di visualizzazione
      Gotoxy(22,76);
      switch(GetKey())//switch di GetKey per il movimento nel menù
      {
         case LEFT : if(i>5)  //caso LEFT
                        i-=5; //incremento percentuale
                     break;
         case RIGHT: if(i<100)//caso RIGHT
                        i+=5; //decremento percentuale
                     break;
         case ENTER: if(Grafo->TotNodes>100) //ENTER calcola percentuale
                        Percent=(Grafo->TotNodes/100)*i;
                     else  
                        Percent=Grafo->TotNodes;
                     LinkLD (Grafo,Percent);
                     Exit=1;
                     break;
         case BACKSPACE: Exit=1; //BACKSPACE per uscire
                         break;
      }
   }while(!Exit);
}
