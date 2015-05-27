#include "libstack.h"
/*-----------------------------------------------------------------------------*
| Libreria di funzioni per la gestione di uno stack                            |
|                                                                              |
|                                                                              |
| Data creazione: 22/12/2008            Autore: Cittadini Paolo e Arcadio Ciro |
*-----------------------------------------------------------------------------*/
void Init_STACK
(
   STACK **Stk
)
{
	*Stk=NULL;
}

TREE* Pop_STACK
(
   STACK** Stk
)
{
	STACK *Tmp;
   TREE  *Elem;
   
   Elem=NULL;
	Elem=(*Stk)->Item;
	Tmp=*Stk;
   *Stk=(*Stk)->Next;
	free(Tmp);
   return Elem;
}

void Push_STACK
(
   TREE *Elem,
   STACK** Stk
)
{
	STACK *Tmp;
	Tmp=(STACK*)malloc(sizeof(STACK));
   Tmp->Item=Elem;
	Tmp->Next=*Stk;
	*Stk=Tmp;
}
void Free_STACK
(
   STACK** Stk
)
{
   STACK* Tmp;
   while((*Stk)!=NULL)
   {
      Tmp=(*Stk)->Next;
      free((*Stk)->Item);
      free(*Stk);
      *Stk=Tmp;
   }
}

boolean Empty_STACK
(
   STACK **Stk
)
{
   boolean EMPTY;
   if(Stk==NULL)
      EMPTY=true;
   else
      EMPTY=false;
   return EMPTY;
}

