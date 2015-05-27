#include "../include/libtree.h"
/*-----------------------------------------------------------------------------*
| StackToTree: trasforma uno stack in un albero binario.                       |
|                                                                              |
|              Per ogni elemento dello stack, il link sinistro viene collegato |
| al primo elemento successivo non ancora puntato; il link destro, al secondo  |
| elemento non ancora puntato. Al termine dello stack, ogni elemento (fatta    |
| eccezione per le foglie), avra'un figlio destro e uno sinistro.              |
|                                                                              |
| Data creazione: 16/01/2009                              Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/
TREE* StackToTree
(
   STACK** Stk, // stack di partenza
   int *c       // numero di elementi inseriti nell'albero
)
{
   int i,j;
   int Exit;
   TREE* Root;
   STACK* Tmp;
   
   Exit=0;
   Root=(*Stk)->Item;
   (*c)++;
   j=1;
   
   do
   {
      Tmp=*Stk;
      for(i=0;i<j;i++)
         Tmp=Tmp->Next;
      
      if(Tmp!=NULL)
      {   
         (*Stk)->Item->Left=Tmp->Item, (*c)++;   // punta al figlio sinistro
         if(Tmp->Next!=NULL)
            (*Stk)->Item->Right=Tmp->Next->Item, (*c)++; // punta al figlio
         else                                            // destro
            Exit=1;
      }
      else
         Exit=1;
      Pop_STACK(Stk); // rilascia la foglia attuale
      j++;
   }while(!Exit);
   do
      Pop_STACK(Stk);   // rilascia le ultime foglie puntate dallo stack
   while(*Stk!=NULL);
   return Root;
}

