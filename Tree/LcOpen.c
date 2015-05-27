#include "../include/libtree.h"
#include "../include/lcfile.h"
/*-----------------------------------------------------------------------------*
| LcOpen      : legge un file caricandolo in un albero binario.                |
|                                                                              |
|                                                                              |
| Data creazione: 16/12/2008                              Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/
int LcOpen
(
   TREE** Tree  //albero di OutPut
)
{
   int Error;   //stato d'errore
   int TotLeafs;//totale foglie
   FILE *lc;    //file da leggere
   char *ReadBuffer;//buffer di lettura
   STACK *Stk;      //stack temporaneo
   
   TotLeafs=0;
   //allocazione del buffer
   ReadBuffer=(char*)calloc(BUFFSIZE,sizeof(char));
   
   Error=0;
   //Path del file
   lc=fopen("maps/cities.lc","r");
   //se l'apertura è andata a buon fine
   if(lc!=NULL)
   {
      do
         PopChar(lc,&ReadBuffer);
      //i caratteri restituiti da PopChar vengono salvati nel Buffer
      while(IsTag(ReadBuffer)!=BEGIN && !feof(lc));
      //Init dello STACK
      Init_STACK(&Stk);
      //Chiamata a ReadClass
      ReadClass(lc,&Stk);
      //chiusura del FILE
      fclose(lc);
   }
   else
      Error=202; //stato d'errore
   //conversione dello stack in albero tramite visita in ampiezza   
   *Tree=StackToTree(&Stk,&TotLeafs);
   //viene liberata la memoria usata dallo stack
   Free_STACK(&Stk);
   //liberazione del buffer di lettura   
   free(ReadBuffer);
   //ritorno dello stato d'errore  
   return Error; 
}
