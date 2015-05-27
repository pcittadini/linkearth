#include "../include/libtree.h"
#include "../include/lcfile.h"
/*-----------------------------------------------------------------------------*
| LoadLeaf: legge un file caricandolo in un albero binario.                    |
|                                                                              |
|                                                                              |
| Data creazione: 16/12/2008                              Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/
int LoadLeaf
(
   FILE *lc,          // file di origine
   TREE **Tree       // struttura (destinazione)
)
{
   int Estat;         // variabile contenente lo stato di errore
   int Exit;          // condizione di uscita: 0 = continua iterazione
                      //                       1 = ferma iterazione
   int Stop;          // flag di caricamento:  0 = continua a caricare campo
                      //                       1 = ferma caricamento
   char *ReadBuffer;  // buffer di lettura per il caricamento [dim BUFFSIZE]
  
   Exit=0;
   Estat=0;
   ReadBuffer=(char*)calloc(BUFFSIZE,sizeof(char));
   
   do
   {
      PopChar(lc,&ReadBuffer);            // raggiunge la prima apertura tag
      if(!feof(lc))           // verifica assenza di termine di file inaspettato
      {
      PopChar(lc,&ReadBuffer); // carica il tag nel buffer
      if(!feof(lc))           // verifica assenza di termine di file inaspettato
         switch(IsTag(ReadBuffer))// identifica tag contenuto nel buffer
         {
///////////////////casi di caricamento di tipo alfanumerico/////////////////////
            case CITY : Stop=0;   // trovato tag
                        do 
                        {
                           PopChar(lc,&ReadBuffer); // carica parola nel buffer
                           if (!feof(lc))
                              if(IsTag(ReadBuffer)!=endCITY)
                              {
                                 // se la parola non supera BUFFSIZE 
                                 if((strlen((*Tree)->City)+strlen(ReadBuffer))<=BUFFSIZE)
                                 // concatena stringhe eventualmente separate
                                 // da caratteri non accettati e le carica nel
                                 // campo della struttura.                                 
                                 strncat((*Tree)->City,ReadBuffer,BUFFSIZE);
                              }
                              else 
                                 Stop=1;           // trovato end, termina 
                           else                    // caricamento
                           {
                              // il file è terminato in modo inaspettato
                              // ferma caricamento e segnala errore
                              Stop=1; 
                              Exit=1; 
                              Estat=13;
                           }
                        }
                        while(!Stop);     // finchè non si verifica errore o 
                        break;            // viene trovato end
                      
         case REGION  : Stop=0;
                        do 
                        {
                           PopChar(lc,&ReadBuffer);
                           if (!feof(lc))
                              if(IsTag(ReadBuffer)!=endREGION)
                              {
                                 (*Tree)->Region=atoi(ReadBuffer);
                              }
                              else
                                 Stop=1;   
                           else
                           {
                              Stop=1; 
                              Exit=1; 
                              Estat=14;
                           }
                        }
                        while(!Stop);
                        break;
       
         case LAT     : Stop=0;
                        do 
                        {
                           PopChar(lc,&ReadBuffer);
                           if (!feof(lc))
                              if(IsTag(ReadBuffer)!=endLAT)
                              {
                                 (*Tree)->Lat=atof(ReadBuffer);
                              }
                              else
                                 Stop=1;  
                           else
                           {
                              Stop=1; 
                              Exit=1; 
                              Estat=16;
                           }
                        }
                        while(!Stop);
                        break;
                      
         case LONG    : Stop=0;
                        do 
                        {
                           PopChar(lc,&ReadBuffer);
                           if (!feof(lc))
                              if(IsTag(ReadBuffer)!=endLONG)
                              {
                                 (*Tree)->Long=atof(ReadBuffer);
                              }
                              else
                                 Stop=1;
                           else
                           {
                              Stop=1; 
                              Exit=1; 
                              Estat=19;
                           }
                        }            
                        while(!Stop);
                        break;
         
         case endCLASS: Exit=1;    // trovato descrittore di fine classe: 
                                   // il caricamento termina senza errori
                        break;
         }
         else Exit=1, Estat=11;    // chiusura inaspettata del file
      }
      else Exit=1, Estat=11;       // chiusura inaspettata del file
   }
   while(!Exit);
   
   free(ReadBuffer);
   return Estat;
}
