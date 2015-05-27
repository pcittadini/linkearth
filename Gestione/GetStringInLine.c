#include "../include/GUI.h"
#include "../lib/platform/platform.h"
#include <string.h>
#include <ctype.h>
#define CHARBUFF 24
#define NUMBUFF 12
/*-----------------------------------------------------------------------------*
|  1. GetchInLine                                                              |
|  2. GetNumInLine                                                             |
|                                                                              |
| Procedure per l'inserimento di caratteri o numeri in una stringa.            |
| Si occupano anche della relativa stampa a video di ogni inserimento,         |
| riducendo il campo visivo ad una riga di lunghezza pari a quella di 27       |
| caratteri.                                                                   |
| Restituiscono una stringa di di dimensioni massime BUFFSIZE:                 |
|     GetchInLine = alfanumerica (comprensiva dei soli caratteri stampabili)   |
|     GetNumInLine= numerica (con cifre comprese tra 0 e 9)                    |
|                                                                              |
| Data creazione: 28/11/2008                              Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------*
|////////////////////////Procedura GetchInLine/////////////////////////////////|
*-----------------------------------------------------------------------------*/
char* GetchInLine 
(
   int c,          // carattere di inizio stringa
   int line        // posizione della riga sullo schermo
)
{
   char* string;   // buffer di lettura e stringa di output [max BUFFSIZE]
   int i;          // indice della stringa [da 0 a 26]
                   // permette l'inserimento fino al limite imposto dal campo
   int j;          // indice di "overflow" [da 0 a BUFFSIZE-1]
                   // permette l'inserimento oltre il limite imposto dal campo
   int t;          

   j=0;
   i=0;
   string=(char*)calloc(CHARBUFF,sizeof(char));

   SetColor(TXT,BKGRND);
   do
   {
      if((isprint(c)||c==32)&&(c!=60&&c!=62&&c!=47))
      //c stampabile e diverso da < (60), > (62) e / (47)
      {  
         if ((i+j)<CHARBUFF-1)               // se il buffer non è pieno
         {
            if(i<27)                         // se non è stato raggiunto il
            {                                // margine, inserisce il carattere
               string[i]=c;                  // nel buffer di lettura;
               printf("%c",c);               // stampa a video il carattere
               i++;                          // e incrementa i
            }
            else                             // se il margine è stato raggiunto
            {                                // 
               Gotoxy(line+6,30);            // 
               for(t=1+j;t<27+j;t++)         // scorre il testo all'interno
                  printf("%c",string[t]);    // del campo inserimento;
               string[i+j]=c;                // aggiunge il carattere nel buffer
               printf("%c",string[i+j]);     // stampa a video il carattere
               j++;                          // e incrementa j
            }
         }
      }
      else if(c==BACKSPACE)                 // se BACKSPACE è stato premuto
           {
             if(i>=27)                      // se le dimensioni della stringa
             {                               // superano quelle del buffer
               if(j>=0)                      // 
                {                            //  
                  Gotoxy(line+6,30);         // 
                  for(t=j;t<i+j;t++)         // scorre il testo all'interno del
                     printf("%c",string[t]); // campo inserimento;
                  j--;                       // e decrementa j.
                }
                else                         // altrimenti
                  i--, j=0;                  // decrementa i e resetta j.
                  
                string[i+j]='\0';            // elimina l'ultimo carattere
                Gotoxy(line+6,26+30);        // inserito e sposta il cursore
                printf(" ");                 // alla fine del testo stampato
                Gotoxy(line+6,26+30);   
             }
             else if(i>0)                  // se invece, la stringa non supera 
             {                             // il buffer ed è presente almeno un 
                i--;                       // carattere: 
                string[i+j]='\0';            // elimina l'ultimo carattere
                Gotoxy(line+6,i+30);         // inserito e sposta il cursore
                printf(" ");                 // alla fine del testo stampato
                Gotoxy(line+6,i+30);
             }
           }
   c=GetKey();                               // ottiene il prossimo input
   }while(c!=ENTER);                         // tutto finchè non viene premuto
   TextReset();                              // ENTER
   return string;
}
/*-----------------------------------------------------------------------------*
|////////////////////////Procedura GetNumInLine////////////////////////////////|
*-----------------------------------------------------------------------------*/
char* GetNumInLine 
(
   int c,          // carattere di inizio stringa
   int line        // posizione della riga sullo schermo
)
{
   char* string;   // buffer di lettura e stringa di output [max BUFFSIZE]
   int i;          // indice della stringa [da 0 a 26]

   i=0;
   string=(char*)calloc(NUMBUFF,sizeof(char));
   
   SetColor(TXT,BKGRND);
   do
   {
      if(isdigit(c)&&i<NUMBUFF-1)        // c deve necessariamente essere un 
      {                                  // numero da 0 a 9
         if(i<27)                         // se non è stato raggiunto il margine
         {
            string[i]=c;                  // inserisce il numero nella stringa
            printf("%c",c);               // stampa a video il numero
            i++;                          // incrementa l'indice
         }
      }
      else if(c==BACKSPACE) // nel caso ci sia BACKSPACE in input
           {
             if(i>0)                      // se è presente almeno un numero
             {
                i--;                      
                string[i]='\0';           // elimina l'ultimo numero
                Gotoxy(line+6,i+30);      
                printf(" ");
                Gotoxy(line+6,i+30);      // visualizza l'eliminazione
             }
           }
   c=GetKey();              // ottiene il prossimo input
   }while(c!=ENTER);        // esegue finchè non viene premuto ENTER
   return string;
   TextReset();
}
