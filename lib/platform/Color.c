#include "platform.h"
/*-----------------------------------------------------------------------------*
| Color.c:                                                                     |
| set di function per la formattazione del testo da stampare nel terminale     |
|                                                                              |
| Creazione: 06/11/2008                 Autori: Arcadio Ciro e Cittadini Paolo |
*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*
| [+]Aggiunta function _SetColor                                  [13.01.2009] |
| [+]Aggiunta function _TextReset                                 [13.01.2009] |
*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*
| SetColor (priorita' bassa)                                                   |
*-----------------------------------------------------------------------------*/
void SetColor
(
   unsigned short int Color,
   unsigned short int Bg
)
{

#ifdef _GNU_SOURCE
   printf("\e[%dm",Color);
   printf("\e[%dm",Bg+10);
#else
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((Bg*16)+(Color)));
#endif
}
/*-----------------------------------------------------------------------------*
| _SetColor (priorita' alta)                                                   |
*-----------------------------------------------------------------------------*/
void _SetColor
(
   unsigned short int Color,
   unsigned short int Bg
)
{

#ifdef _GNU_SOURCE
   fprintf(stderr,"\e[%dm",Color);
   fprintf(stderr,"\e[%dm",Bg+10);
#else
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((Bg*16)+(Color)));
#endif
}
/*-----------------------------------------------------------------------------*
| TextReset (priorita' bassa)                                                  |
*-----------------------------------------------------------------------------*/
void TextReset()
{
#ifdef _GNU_SOURCE
   printf("\e[;m");
#else
   SetColor(STD,BLACK);
#endif
}
/*-----------------------------------------------------------------------------*
| _TextReset (priorita' alta)                                                  |
*-----------------------------------------------------------------------------*/
void _TextReset()
{
#ifdef _GNU_SOURCE
   fprintf(stderr,"\e[;m");
#else
   SetColor(STD,BLACK);
#endif
}
