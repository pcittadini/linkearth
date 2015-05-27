#include "../lib/platform/platform.h"
#include "../include/lcfile.h"
#include "../include/GUI.h"

int BKGRND;
int TXT;
int HBKGRND;
int HTXT;

/*-----------------------------------------------------------------------------*
| GetConf: function per la lettura di un piccolo file di configurazione        |
|                                                                              |
|          Legge e assegna i valori delle variabili di tipo extern dal         || file di configurazione "SYSTEM".conf. SYSTEM e' definito in platform.h.      |
|                                                                              |
| Data creazione: 28/01/2009                              Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/

void GetConf()
{
   char *ReadBuffer;                    // stringa di supporto
   FILE *Conf;
   Conf=fopen(SYSTEM".conf","r");    // apre il file
   ReadBuffer=(char*)calloc(BUFFSIZE,sizeof(char));
   
   if(!Conf) // se il file non e' presente crea un nuovo file con configurazione
   {         // standard
      BKGRND=BLUE;
      TXT=WHITE;
      HBKGRND=RED;
      HTXT=WHITE;
      SetConf();
   }
   else      // altrimenti carica le impostazioni dal file
   {
      do
         PopChar(Conf,&ReadBuffer);
      while(strcmp(ReadBuffer,"Colors") && !feof(Conf));
      
      PopChar(Conf,&ReadBuffer);
      PopChar(Conf,&ReadBuffer);
      TXT=atoi(ReadBuffer);
      
      PopChar(Conf,&ReadBuffer);
      PopChar(Conf,&ReadBuffer);
      BKGRND=atoi(ReadBuffer);
      
      PopChar(Conf,&ReadBuffer);
      PopChar(Conf,&ReadBuffer);
      HTXT=atoi(ReadBuffer);
      
      PopChar(Conf,&ReadBuffer);
      PopChar(Conf,&ReadBuffer);
      HBKGRND=atoi(ReadBuffer);
   }
   fclose(Conf);     // chiude il file
   free(ReadBuffer); // libera la memoria utilizzata dalla stringa di supporto
}
