#include <stdio.h>
#include <stdlib.h>
/*-----------------------------------------------------------------------------*
| In questo header ci sono le definizioni riferite alla gestione del file ".lc"|
|                                                                              |
|                                                                              |
| Data creazione: 22/12/2008            Autore: Cittadini Paolo e Arcadio Ciro |
*-----------------------------------------------------------------------------*/
#ifndef _LC_CITIES_H_  //se i tag non sono precedentemente definiti

#define _LC_CITIES_H_  //definisci l'insieme di costanti
//definizione dei tag del file 
#define BEGIN            1     //   <begin>  //tag inizio file ".lc"
#define END              11    //   <end>    //tag fine file
#define CLASS            2     //   <class>  //inizio classe
#define endCLASS         22    //   </class> //fine classe
#define CITY             3     //   <CITY>   //nome città
#define endCITY          33    //   </CITY>  //fine nome città
#define REGION           4     //   <REG>    //numero regione geodetica
#define endREGION        44    //   </REG>   //fine regione
#define LAT              5     //   <LAT>    //latitudine
#define endLAT           55    //   </LAT>   //fine lat
#define LONG             6     //   <LONG>   //longitudine
#define endLONG          66    //   </LONG>  //fine longitudine

#endif
//definizione delle funzioni operanti sul file
//path: ./Tree

/*[2x13]*/void  PopChar (FILE *lc, char **ReadBuffer);
/*[2x12]*/int   IsTag   (char *ReadBuffer);
