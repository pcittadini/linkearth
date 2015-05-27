#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| Function per la gestione della visualizzazione del grafo                     |
|                                                                              |
|                                                                              |
|                                                                              |
| Data creazione: 24/01/2008                           Autore: Paolo Cittadini |
*-----------------------------------------------------------------------------*/
void DispGraph
(
   GRAPH* Grafo, //grafo di input
   int i,        //elemento in visualizzazione
   int j,        //elemento selezionato nella lista archi
   int ArkNum    //numero degli archi del NODO con ID=i
)
{  
   int p;
   int t;
   int Met;
     
   ARK* Ark;     //arco temporaneo di scorrimento
   Ark=Grafo->StartNode[i].Ark;
   
   SetColor(TXT,BKGRND);//settaggio del layout
   Gotoxy(5,5);         //costruzione elementi GUI
   printf("...|");
   Gotoxy(4,9);
   printf("____");
   Gotoxy(6,8);
   printf("|____|");
   Gotoxy(5,13);
   printf("|___");
   Gotoxy(5,33);
   printf("___|");
   Gotoxy(4,37);
   printf("____");
   Gotoxy(6,36);
   printf("|____|");
   Gotoxy(5,41);
   printf("|...");
   Gotoxy(5,17);
   printf("|");
   SetColor(HTXT,HBKGRND);
   //stampa latitudine elemento
   printf("Lat=%10f",Grafo->StartNode[i].Node->Lat);
   SetColor(TXT,BKGRND);
   printf("|");
   Gotoxy(6,17);
   printf("|");
   SetColor(HTXT,HBKGRND);
   //stampa longitudine elemento
   printf("Long=%9f",Grafo->StartNode[i].Node->Long);
   SetColor(TXT,BKGRND);
   printf("|");
   Gotoxy(7,18);printf("ID:%11d",i);
   Gotoxy(9,3);
   printf("------------------DA NODO-------------------");
   Gotoxy(11,5);
   printf("Citta': %32s",Grafo->StartNode[i].Node->City);
   Gotoxy(12,5);
   printf("Regione: %31d",Grafo->StartNode[i].Node->Region);
   Gotoxy(14,3);
   printf("------------------A NODO--------------------");
   //costruzione layout per la visualizzazione degli archi del NODO
   for(p=3;p<22;p++)
      Gotoxy(p,47),printf("|");
   Gotoxy(3,48);
   printf("Archi:");
    
   if(j>15)
   {
      Met=ArkNum/16;
      Met++;
   }
   else
      Met=1;
      
   for(t=1;t<=Met;t++)
   {
      p=0;
      while(p<16&&Ark)
      {
         if(j<(16*t)&&j>=(16*(t-1)))
         {
            if(p==(j%16))
            {
               Gotoxy(16,5);
               printf("Citta': %32s",Grafo->StartNode[Ark->IDLinkedNode].Node->City);
               Gotoxy(17,5);
               printf("Regione: %31d",Grafo->StartNode[Ark->IDLinkedNode].Node->Region);
               Gotoxy(19,5);
               printf("Distanza: %28gKm",Ark->KmDist);
               SetColor(HTXT,HBKGRND);
            }
            Gotoxy(p+5,48);
            printf("%24s",Grafo->StartNode[Ark->IDLinkedNode].Node->City);
            if(p==(j%16))
               SetColor(TXT,BKGRND);
          }
         p++;
         Ark=Ark->NextArk;
      }
   }
   Gotoxy(22,76);
   TextReset();
}
