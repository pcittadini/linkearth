___    |________  ____/__(_)_  ___/________  __/_  /_
__  /| |_  ___/  /    __  /_____ \_  __ \_  /_ _  __/
_  ___ |  /   / /___  _  / ____/ // /_/ /  __/ / /_  
/_/  |_/_/    \____/  /_/  /____/ \____//_/    \__/
********  **       ****    ********** ********** *****   ********  **       **                                                                      
**     ** **       **  **      **     **        **   **  **     ** ***     *** 
**     ** **       **   **     **     *******  **     ** **     ** ** *   * ** 
********  **       ********    **     **       **     ** ********  **  * *  ** 
**        **       **     **   **     **       **     ** ** **     **   *   **   
**        **       **      **  **     **        **   **  **   **   **       ** 
**        ******** **       ** **     **         *****   **     ** **       ** 
                                                _BY_ArcadioCiro&PaoloCittadini
1) INFORMAZIONI GENERALI

   Platform è una libreria che racchiude function di comune utilizzo rese 
portabili sia su Linux che su Windows.                                           
Abbiamo pensato che creare una libreria che semplifichi questi procedimenti 
renda il codice “più pulito” e facile da consultare.
(Si ricorda che per informazioni più dettagliate sulle singole function è 
consigliabile consultare la documentazione interna di ogni singola function)

2) IMPLEMENTAZIONE

   La macro _GNU_SOURCE se definita permette di effettuare lo switch delle 
function. Il compilatore a seconda della piattaforma evita i pezzi di codice non 
portabili al momento.
La libreria è aggiornata di continuo, al momento abbiamo implementato le 
seguenti function:

int  Getch      ();
/* Acquisizione singolo carattere da tastiera */

int _Getch      ();
/*Getchar limitata all'acquisizione di un solo carattere*/

void Gotoxy     (int x, int y);
/* Posizionamento cursore in coordinate*/

void ClearScreen();
/*Reset del Buffer del terminale*/

void SetColor   (unsigned short int Color, unsigned short int Bg);
/*Setta il colore del testo in base ai valori definiti in "platform.h"*/

void TextReset  ();
/*Ripristina i colori di default*/

void Yawn       (float Time);
/*Sleep!!!*/

void CPrintf    (char *fmt, ...);
/*Printf integrato con funzioni di colorazione(Text&Background)*/

int  GetKey     ();
/*Permette di riconoscere ed utilizzare i tasti direzionali */

3)CONTATTI

Paolo Cittadini & Ciro Arcadio.
mail: c.arcadio@studenti.unina.it
mail: behind.the.shell@gmail.com

/*-----------------------------------------------------------------------------*
|                                                                              | 
|  REAL PROGRAMMERS DON'T USE GOTO !!!                                         |
|  REAL PROGRAMMERS DON'T NEED COMMENTS, CODE IS OBVIOUS !!!                   |
|                                                                              |
|                                                                              |
|  SOFTWARE IS LIKE SEX....FREE IS GOOD !!! (Linus Torvald)                    |
|                                                                              |
*-----------------------------------------------------------------------------*/

