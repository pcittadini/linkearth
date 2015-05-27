#include "../include/GUI.h"
/*-----------------------------------------------------------------------------*
| DispForeground: visualizza il layout di un menu tra quelli conosciuti.       |
|                                                                              |
| data di creazione: 13/01/2009                           Autore: Arcadio Ciro |
*-----------------------------------------------------------------------------*/

void DispForeground
(  
   int MenuID,       // ID riconoscimento menu
   int i             // indice di selezione
)
{
   SetColor(TXT,BKGRND);
   switch(MenuID)
   {
      case MenuMAIN: Gotoxy(10,30);printf("  CARICA MAPPA  ");
                     Gotoxy(12,30);printf("GESTISCI RETE LE");
                     Gotoxy(14,30);printf("     OPZIONI    ");
                     Gotoxy(16,30);printf("      ESCI      ");
                     
                     SetColor(HTXT,HBKGRND);
                     Gotoxy(i+10,30);
                     switch(i)
                     {
                        case 0: printf("  CARICA MAPPA  "); break;
                        case 2: printf("GESTISCI RETE LE"); break;
                        case 4: printf("     OPZIONI    "); break;
                        case 6: printf("      ESCI      "); break;
                     }
                     break;
                     
      case MenuTREE: Gotoxy(8,20);
                     printf(" CONTROLLA INTEGRITA' ALBERO DI MEMORIA");
                     Gotoxy(10,20);printf(" SELEZIONA LIVELLO DA PRELEVARE ");
                     Gotoxy(12,20);printf(" CONFERMA ED ESCI");
   
                     // EVIDENZIATORE PULSANTI
                     Gotoxy(i+8,21);
                     switch(i)
                     {
                        case 0: printf(" CONTROLLA INTEGRITA' ALBERO DI MEMORIA");
                                break;
                        case 2: printf(" SELEZIONA LIVELLO DA PRELEVARE ");
                                break;
                        case 4: printf(" CONFERMA ED ESCI");break;
                     }
                     SetColor(HTXT,HBKGRND);
                     Gotoxy(i+8,20);printf(">");
                     break;
                     
      case MenuGRAPH:Gotoxy(8,30);
                     printf("VISUALIZZA GRAFO");
                     Gotoxy(10,30);printf("MODIFICA");
                     Gotoxy(12,30);printf("CERCA PERCORSI");
                     Gotoxy(14,30);printf("ESCI");
   
                     // EVIDENZIATORE PULSANTI
                     Gotoxy(i+8,30);
                     switch(i)
                     {
                        case 0: printf(" VISUALIZZA GRAFO");
                                break;
                        case 2: printf(" MODIFICA");
                                break;
                        case 4: printf(" CERCA PERCORSI");
                                break;
                        case 6: printf(" ESCI");
                                break;
                     }
                     SetColor(HTXT,HBKGRND);
                     Gotoxy(i+8,29);printf(">");
                     break;

      case MenuGRAPH_MOD:Gotoxy(6,25);
                     printf("AGGIUNGI LONG DISTANCE LINKS");
                     Gotoxy(8,25);printf("AGGIUNGI NODO");
                     Gotoxy(10,25);printf("AGGIUNGI ARCO");
                     Gotoxy(12,25);printf("AGGIUNGI HUB");
                     Gotoxy(14,25);printf("ELIMINA NODO");
                     Gotoxy(16,25);printf("ESCI");
   
                     // EVIDENZIATORE PULSANTI
                     Gotoxy(i+6,25);
                     switch(i)
                     {
                        case 0: printf(" AGGIUNGI LONG DISTANCE LINKS");
                                break;
                        case 2: printf(" AGGIUNGI NODO");
                                break;
                        case 4: printf(" AGGIUNGI ARCO");
                                break;
                        case 6: printf(" AGGIUNGI HUB");
                                break;
                        case 8: printf(" ELIMINA NODO");
                                break;
                        case 10: printf(" ESCI");
                                break;
                     }
                     SetColor(HTXT,HBKGRND);
                     Gotoxy(i+6,24);printf(">");
                     break;
      case MenuGRAPH_MOD_A:
                     Gotoxy(6,18);printf("Citta':");
                     Gotoxy(8,18);printf("Regione:");
                     Gotoxy(10,18);printf("Latitudine:");
                     Gotoxy(12,18);printf("Longitudine:");
                     Gotoxy(14,18);printf("Link To:");
                     Gotoxy(16,18);printf("Link To:");
                     Gotoxy(18,18);printf("Target IDs:");
   
                     // EVIDENZIATORE PULSANTI
                     SetColor(HTXT,HBKGRND);
                     if(i<10)
                        Gotoxy(i+6,58),printf("<");
                     break;
                     
      case MenuGRAPH_MOD_H:
                     Gotoxy(6,30);printf("Aggiungi un HUB");
                     Gotoxy(8,18);printf("Nodo:");
                     Gotoxy(10,18);printf("Nodo:");
                     Gotoxy(12,18);printf("Nr. Link:");
                     Gotoxy(18,18);printf("Target IDs:");
   
                     // EVIDENZIATORE PULSANTI
                     SetColor(HTXT,HBKGRND);
                     if(i!=2)
                     {
                        SetColor(HTXT,HBKGRND);
                        Gotoxy(i+6,30); printf("<");
                        Gotoxy(i+6,60); printf(">");
                        SetColor(TXT,BKGRND);
                     }
                     else
                        Gotoxy(i+6,58),printf("<");
                     break;
                     
      case MenuGRAPH_MOD_D:
                     Gotoxy(6,30);printf("Elimina Nodo");
                     Gotoxy(8,18);printf("Nodo:");
                     Gotoxy(10,18);printf("Nodo:");
                     Gotoxy(18,18);printf("Target IDs:");
                     // EVIDENZIATORE PULSANTI
                     SetColor(HTXT,HBKGRND);
                     if(i==2)
                        Gotoxy(i+6,58),printf("<");
                     break;
                     
      case MenuGRAPH_PATH:
                     Gotoxy(7,30);printf("DA NODO");
                     Gotoxy(13,30);printf("A NODO");
                     Gotoxy(9,18);printf("ID Nodo:");
                     Gotoxy(11,18);printf("Citta':");
                     Gotoxy(15,18);printf("ID Nodo:");
                     Gotoxy(17,18);printf("Citta':");
                     // EVIDENZIATORE PULSANTI
                     SetColor(HTXT,HBKGRND);
                     if(i!=4)
                     {
                        if(i==2||i==8)
                        {
                           Gotoxy(i+9,29);printf("<");
                           Gotoxy(i+9,60);printf(">");
                        }
                        else
                           Gotoxy(i+9,58),printf("<");
                     }
                     break;                                             
              
      case MenuOPT : Gotoxy(6,20);
                     printf("Cambia combinazione di colori");
                     Gotoxy(8,20); printf("AZZURRO/MAGENTA");
                     Gotoxy(10,20);printf("BIANCO/ROSSO");
                     Gotoxy(12,20);printf("NERD");
                     Gotoxy(14,20);printf("STANDARD");
                     Gotoxy(16,20);printf("SALVA ED ESCI");
   
                     // EVIDENZIATORE PULSANTI
                     Gotoxy(i+8,21);
                     switch(i)
                     {
                        case 0: printf(" AZZURRO/MAGENTA");
                                break;
                        case 2: printf(" BIANCO/ROSSO");
                                break;
                        case 4: printf(" NERD");
                                break;
                        case 6: printf(" STANDARD");
                                break;
                        case 8: printf(" SALVA ED ESCI");
                                break;
                     }
                     SetColor(HTXT,HBKGRND);
                     Gotoxy(i+8,20);printf(">");
                     break;
   }
   TextReset();
   Gotoxy(22,76);
}
