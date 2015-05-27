#include "../include/libtree.h"
#include "../include/lcfile.h"
/*-----------------------------------------------------------------------------*
| ReadClass: function ricorsiva per la lettura di una classe                   |
|                                                                              |
|                                                                              |
| Data creazione: 16/12/2008                              Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/
int ReadClass
(
   FILE *lc,    //file da leggere
   STACK **Stack//stack degli elementi caricati dal file
)
{
   int Tag,Error;//tag numerici e stato d'errore
   char *ReadBuffer;//buffer di lettura
   TREE *Leaf;//foglie dell'alero da caricare nello stack
   //allocazione del buffer di lettura
   ReadBuffer=(char*)calloc(BUFFSIZE,sizeof(char));
   Leaf=NULL;
   //2 --> NESSUN ERRORE
   Error=2;

   do
   {  //scansione del file carattere per carattere
      PopChar(lc,&ReadBuffer);
      //verifica eventuali TAG
      Tag=IsTag(ReadBuffer);
   }             
   while(!Tag && !feof(lc));
   switch(Tag)  //switch del TAG trovato
   {
      case CLASS : NewLeaf(&Leaf);        //CLASSE trovata
                   LoadLeaf(lc,&Leaf);    //acquisizione delle informazioni
                   Push_STACK(Leaf,Stack);
                   ReadClass(lc,Stack);
                   break;
                   
      case END   : Error=0; break;         //fine del FILE
   }
   free(ReadBuffer);//liberazione memoria del buffer di lettura
   return Error;//ritorno dello stato d'errore
}
