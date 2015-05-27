#include "../lib/platform/platform.h"
#include "../include/GUI.h"

/*-----------------------------------------------------------------------------*
| SetConf: function per il salvataggio di un piccolo file di configurazione    |
|                                                                              |
|          Stampa sul file "SYSTEM".conf il valore delle variabili di tipo     || extern dichiarate in GUI.h e definite dall'utente.                           |
|                                                                              |
| Data creazione: 28/01/2009                              Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/

void SetConf()
{
   FILE *Conf;
   Conf=fopen(SYSTEM".conf","w");
   
   fprintf(Conf,SYSTEM" Link Earth configuration\nColor Range:\n");
   fprintf(Conf,"[%d BLACK, %d BLUE, %d GREEN, ",BLACK,BLUE,GREEN);
   fprintf(Conf,"%d CYAN, %d RED, %d MAGENTA, ",CYAN,RED,MAGENTA);
   fprintf(Conf,"%d GREY, %d YELLOW, %d WHITE]\n\n",GREY,YELLOW,WHITE);
   fprintf(Conf,"<Colors>\n");
   fprintf(Conf,"Text Color       <%d>\n",TXT);
   fprintf(Conf,"Background Color <%d>\n",BKGRND);
   fprintf(Conf,"HText Color      <%d>\n",HTXT);
   fprintf(Conf,"HBackground Color<%d>\n",HBKGRND);
   fprintf(Conf,"<Colors>");
   fclose(Conf);
}
