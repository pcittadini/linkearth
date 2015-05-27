#include "../include/lcfile.h"
#include <string.h>
/*-----------------------------------------------------------------------------*
| IsTag: routine per l'identificazione dei tag prelevati dal file.             |
|                                                                              |
|                                                                              |
| Data di creazione: 14/11/2008                       Autore: Paolo Cittadini  |
*-----------------------------------------------------------------------------*/

int IsTag
(
   char *ReadBuffer //Buffer di lettura 
)
{
   int Tag;         //Valore Numerico del Tag da restituire
   Tag=0;
   
   if (!strcmp(ReadBuffer,"begin"))  //Verifica se Nel Buffer è presente il TAG   
         Tag=BEGIN;                       
         
   if (!strcmp(ReadBuffer,"end"))
         Tag=END;
   
   if (!strcmp(ReadBuffer,"class"))
         Tag=CLASS;
   
   if (!strcmp(ReadBuffer,"/class"))
         Tag=endCLASS;

   if (!strcmp(ReadBuffer,"CITY"))
         Tag=CITY;
   
   if (!strcmp(ReadBuffer,"/CITY"))
         Tag=endCITY;

   if (!strcmp(ReadBuffer,"REG"))
         Tag=REGION;
   
   if (!strcmp(ReadBuffer,"/REG"))
         Tag=endREGION;

   if (!strcmp(ReadBuffer,"LAT"))
         Tag=LAT;
   
   if (!strcmp(ReadBuffer,"/LAT"))
         Tag=endLAT;

   if (!strcmp(ReadBuffer,"LONG"))
         Tag=LONG;
   
   if (!strcmp(ReadBuffer,"/LONG"))
         Tag=endLONG;

return Tag;   //ritorna il valore del TAG el chiamante
}
