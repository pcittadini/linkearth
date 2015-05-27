#include "../include/libgraph.h"
#include <math.h>
/*-----------------------------------------------------------------------------*
| GeoDist: Questa funzione calcola la distanza tra due punti sulla superfice   |
| terrestre, date le coordinate in latitudine e longitudine espresse in gradi  |
| decimali.                                                                    |
|                                                                              |
| Data creazione: 23/12/2008                           Autore: Paolo Cittadini |
*-----------------------------------------------------------------------------*/
double GeoDist 
(
   double LatA, 
   double LonA,
   double LatB, 
   double LonB
)
{
   /* Definisce le costanti e le variabili */
   const double R = 6371;
   const double PiGreco = 3.1415927;
   double Lat_alfa, Lat_beta;
   double Lon_alfa, Lon_beta;
   double fi;
   double p, KmDist;

   /* Converte i gradi in radianti */
   Lat_alfa = (PiGreco * LatA) / 180;
   Lat_beta = (PiGreco * LatB) / 180;
   Lon_alfa = (PiGreco * LonA) / 180;
   Lon_beta = (PiGreco * LonB) / 180;

   /* Calcola l'angolo compreso 'fi' */
   fi = fabs(Lon_alfa - Lon_beta);

   /* Calcola il terzo lato del triangolo sferico */
   p = acos(sin(Lat_beta) * sin(Lat_alfa) + 

   cos(Lat_beta) * cos(Lat_alfa) * cos(fi));
   
   /* Calcola la distanza sulla superficie terrestre R = ~6371 km */
   KmDist = p * R;

   return(KmDist);
}

