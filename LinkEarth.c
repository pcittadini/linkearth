#include "lib/stack/libstack.h"
#include "include/libgraph.h"
#include "lib/platform/platform.h"
#include "include/GUI.h"
/*-----------------------------------------------------------------------------*
| LinkEarth                                                                    |
| Data ultima modifica: 05/02/09        Autore: Cittadini Paolo e Arcadio Ciro |
*-----------------------------------------------------------------------------*/
int main()
{  
   int i;
   int Exit;
   STACK *Stack;
   GRAPH Grafo;
   
   i=0;
   Exit=0;
   Stack=NULL;
   //inizializzazione grafo
   Grafo.TotNodes=0;
   Grafo.MaxAllocNode=0;
   Grafo.StartNode=NULL;
   
   ClearScreen();          // Cleaning dello schermo
   GetConf();              // legge la configurazione
   Splash();               // SplashScreen
   do
   {
      DispBackground();    // visualizza un background vuoto
      DispForeground(MenuMAIN,i); // visualizza informazioni di foreground
      
      switch(GetKey())
      {
         case UP   : if(i!=0)  //viene gestito il movimento all'interno del menu
                        i-=2;
                     break;
         case DOWN : if(i<6)
                        i+=2;
                     break;
         case ENTER: switch(i)
                     {
                        case 0 : if(Stack)             // se è già presente uno
                                    Free_STACK(&Stack);// stack, esegue il free
                                 MenuTree(&Stack);     // carica elementi nello
                                 if(Grafo.TotNodes)    // stack       
                                    FreeGraph(&Grafo); 
                                 break;
                        case 2 : if(Stack||Grafo.TotNodes) // verifica se sono
                                 {                         // presenti strutture
                                    if(!Grafo.TotNodes)    // allocate
                                       StackToGraph(&Stack,&Grafo);
                                       // crea il grafo e avvia il menu relativo
                                    MenuGraph(&Grafo);  
                                 }
                                 break;
                        case 4 : MenuOption(); // avvia il menu per le opzioni
                                 SetConf();    // salva le opzioni
                                 break;
                        case 6 : if(Stack)         // libera eventuali strutture 
                                    Free_STACK(&Stack);      // allocate ed esce
                                 FreeGraph(&Grafo);
                                 Exit=1;
                                 break;
                     }
                     break;
         case ESC  : if(Stack)
                        Free_STACK(&Stack);
                     FreeGraph(&Grafo);
                     Exit=1;
                     break;
      }
   }
   while(!Exit);
   
   ClearScreen();
   return 0;
}
