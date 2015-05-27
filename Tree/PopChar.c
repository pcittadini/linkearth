#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef BUFFSIZE
#define BUFFSIZE 128
#endif
/*-----------------------------------------------------------------------------*
| PopChar: dato un file ed una stringa di lunghezza BUFFSIZE-1, riempie        |
|          quest'ultima con caratteri compresi tra < e > in un file di tipo lc |
|                                                                              |
| Legge un carattere e lo inserisce nella stringa di output, finchè lo stesso  |
| non è uguale a < o >, o viene raggiunta la fine del file.                    |
| Restituisce una stringa di dimensioni al massimo pari a BUFFSIZE             |                                                                          |
|                                                                              |
| data di creazione:       16/11/2008                                          |
| data di ultima modifica: 22/12/2008                     Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/
/*CRONOLOGIA MODIFICHE*/
/*-----------------------------------------------------------------------------*
| [+]Risolo memory leak                                           [22.12.2008] |
|                                                                              |
| La precedente versione non permetteva una corretta gestione della memoria    |
| dinamica in quanto, ad ogni chiamata, venivano allocati BUFFSIZE bytes che   |
| non venivano direttamente liberati al termine della routine.                 |
|                                                                              |
| La function è ora di tipo void e prevede due input: FILE*                    |
|                                                     char** (dim BUFFSIZE)    |
|                                                     [input/output]           |
| La gestione della memoria dedicata alla stringa potrà quindi essere          |
| effettuata esternamente alla function.                                       |
| Siccome non è più possibile lavorare su stringhe sicuramente "pulite", il    |
| termine di stringa viene forzato al termine della lettura (line 51)          |
|                                                                              |
|                                                                 Arcadio Ciro |
*-----------------------------------------------------------------------------*/
void PopChar
(
   FILE *lc,
   char **ReadBuffer
)
{
   int i;            
   char Key;         // carattere da processare
      
   i=0;
   
   //ottiene Key dal file finchè non trova "<" o ">" o EOF
   while(Key=fgetc(lc),Key!=60&&Key!=62&&!feof(lc)&&i<BUFFSIZE-1)
   {
      (*ReadBuffer)[i]=Key;   // salva i caratteri letti nel Buffer
      i++; 
   }
   (*ReadBuffer)[i]='\0';     // termina la stringa
}
