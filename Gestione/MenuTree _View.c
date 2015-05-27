#include "../include/libtree.h"
#include "../lib/platform/platform.h"
#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| MenuTree_View: struttura per menu interattivo                                |
|                                                                              |
|            Tramite un indice, permette l'interazione e la selezione di       || una lista di funzioni con un semplice input da tastiera.                     |
| Permette di visualizzare un albero binario di n livelli, dividendo la stampa |
| in più pagine. Nella parte bassa dello schermo sono visualizzate le info     |
| sul nodo selezionato e i relativi figli. il tasto destro sposta il cursore   |
| sul figlio destro e quello sinistro, sul nodo sinistro. Il tasto UP sposta   |
| il cursore sul nodo padre.                                                   |
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
void MenuTree_View
(
   TREE *Root,     // radice dell'albero
   TREE *Tree,     // foglia puntata
   int i,
   int j,
   int Level,      // livello attuale
   int Begin,
   int*End
)
{
   int Step;
   int Up;
   Up=0;
  
   if(Tree)
   do
   {
      // stampa info
      _DispBackground();
      _SetColor(TXT,BKGRND);
      DispTree(Root,5,39,4);
      _Gotoxy(15,16);
      fprintf(stderr,"Nodo attuale:%34s",Tree->City);
      if(Tree->Left)
      {
      _Gotoxy(16,16);
      fprintf(stderr,"Nodo sinistro:%33s",Tree->Left->City);
      }
      if(Tree->Left)
      {
      _Gotoxy(17,16);
      fprintf(stderr,"Nodo destro:%35s",Tree->Right->City);
      }
      _Gotoxy(i,j);
      _SetColor(HTXT,HBKGRND);
      _Gotoxy(i,j);
      fprintf(stderr,"O");
      _TextReset();
      _Gotoxy(22,76);
      
      if (Level<3)
         switch(Level)
         {
            case 2: Step=3;break;
            case 1: Step=2;break;
         }
      else
         Step=(Level*(Level-1));
      
      
      switch(GetKey())
      {
         case UP   : if(Level!=4||!Begin)
                     {
                        Up=1;
                     }
                     break;
         case LEFT : if(Tree->Left)
                     {
                        // effettua una ricorsione in base alla posizione del 
                        // cursore
                        if(Level)
                           MenuTree_View(Root,Tree->Left,i+2,j-Step,Level-1,0,End);
                        else
                           MenuTree_View(Tree->Left,Tree->Left,5,39,4,0,End);
                     }
                     break;
         case RIGHT: if(Tree->Right)
                     {
                        // effettua una ricorsione in base alla posizione del 
                        // cursore
                        if(Level)
                           MenuTree_View(Root,Tree->Right,i+2,j+Step,Level-1,0,End);
                        else
                           MenuTree_View(Tree->Right,Tree->Right,5,39,4,0,End);
                     }
                     break;
         case BACKSPACE:(*End)=1;
                        break;
      }
   }
   while(!(*End)&&!Up);
   if(Begin)
      *End=0;
}
