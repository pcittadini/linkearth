/*-----------------------------------------------------------------------------*
|platform.h: Header file per funzioni multipiattaforma.                        |
|                                                                              |
|Supporta sistemi operativi Unix e Microsoft tramite direttive al preprocessore|
|per la compilazione condizionale. Viene quindi utilizzata la macro            |
|"_GNU_SOURCE" che, se definita, permette la compilazione del codice supportato|
|dai sistemi Unix, altrimenti quella del codice compatibile con sistemi        |
|Microsoft o BSD.                                                              |
|In questo caso rendiamo il codice portabile su:                               |
|1)GNU-Linux (kernel >= 2.6)(testato su Ubuntu 8.04) 									 |
|2)MS-Windows(9x, XP, Vista)                                                   |
|																									    |
| Creazione: 24/10/2008                 Autori: Arcadio Ciro e Cittadini Paolo |
*-----------------------------------------------------------------------------*/
/*CRONOLOGIA MODIFICHE*/
/*-----------------------------------------------------------------------------*
| [+]Aggiunti i prototipi di Colori.c                             [06.11.2008] |
| [+]Aggiunta function Yawn per la portabilità dello sleep        [06.11.2008] |
| [+]Inclusa libreria <stdarg.h>                                  [07.11.2008] |
| [+]Aggiunta function CPrintf                                    [07.11.2008] |
| [+]Aggiunta function _Getch(nel file Getch.c)                   [20.11.2008] |
| [+]Aggiunta function GetKey()                                   [20.11.2008] |
| [+]Aggiunta function _Gotoxy()                                  [13.01.2009] |
*-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#ifdef _GNU_SOURCE               
/*-----------------------------------------------------------------------------*
|Inclusione librerie UNIX                                                      |
*-----------------------------------------------------------------------------*/
#define SYSTEM "LINUX"
#include <termios.h>
#include <unistd.h>

//Colori LINUX
#define BLACK     30            /*NERO*/
#define RED       31            /*ROSSO*/
#define GREEN     32            /*VERDE*/
#define YELLOW    33            /*GIALLO*/
#define BLUE      34            /*BLU*/
#define MAGENTA   35            /*MAGENTA*/
#define CYAN      36            /*AZZURRO*/
#define WHITE     37            /*BIANCO*/
#define GREY      37
#define STD       0             /*Standard*/

//TASTIERA ESTESA PER "GetKey()"
#define ESC       27
#define LEFT      27+91+68
#define RIGHT     27+91+67
#define UP        27+91+65
#define DOWN      27+91+66
#define ENTER     10
#define BACKSPACE 127


#else
/*-----------------------------------------------------------------------------*
|Inclusione delle librerie per sistemi MICROSOFT                               |
*-----------------------------------------------------------------------------*/
#define SYSTEM "WINDOWS"
#include <windows.h>
#include <conio.h>

//Colori WINDOWS
#define BLACK     0            /*NERO*/
#define RED       4            /*ROSSO*/
#define GREEN     2            /*VERDE*/
#define YELLOW    14           /*GIALLO*/
#define BLUE      1            /*BLU*/
#define MAGENTA   5            /*MAGENTA*/
#define CYAN      3            /*AZZURRO*/
#define WHITE     15           /*BIANCO*/
#define GREY      7
#define STD       7            /*Standard*/

//TASTIERA ESTESA(WINDOWS(SUCK)) PER "GetKey()"
#define ESC       224
#define LEFT      224+100+75
#define RIGHT     224+100+77
#define UP        224+100+72
#define DOWN      224+100+80
#define ENTER     13
#define BACKSPACE 8

#endif

/*-----------------------------------------------------------------------------*
|Dichiarazione delle function multipiattaforma                                 |
*-----------------------------------------------------------------------------*/
int  Getch      ();
int  _Getch     ();
void Gotoxy     (int x, int y);
void _Gotoxy    (int x, int y);
void ClearScreen();
void SetColor   (unsigned short int Color, unsigned short int Bg);
void _SetColor  (unsigned short int Color, unsigned short int Bg);
void TextReset  ();
void _TextReset ();
void Yawn       (float Time);
void CPrintf    (char *fmt, ...);
int  GetKey     ();
