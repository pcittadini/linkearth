#include "platform.h"
/*-----------------------------------------------------------------------------*
| Cprintf : integrazione di alcune funzionalità  nel printf.                   |
|                                                                              |
| Creazione: 07/11/2008                 Autori: Arcadio Ciro e Cittadini Paolo |
*-----------------------------------------------------------------------------*/

void CPrintf
(
   char *fmt,
   ...
)
{
   va_list ap;        //Punta in sequenza ad ogni argomento anonimo
   
   char    *p, *sval;
   int     cval;
   int     ival;
   int     tval;      //[+]'%t' ---> SetColor Text
   int     bval;      //[+]'%b' ---> SetColor Background
   double  dval;

   va_start(ap,fmt);  //Fa puntare ap al primo argomento anonimo 
   for(p=fmt;*p;p++)
   {
      if(*p != '%')
      {
         putchar(*p);
         continue;
      }
   
      switch(*++p)
      {
         case 'c':
            cval=va_arg(ap, int);
            printf("%c",cval);
            break;
         case 'd':
            ival=va_arg(ap, int);
            printf("%d",ival);
            break;
         case 'f':
            dval=va_arg(ap, double);
            printf("%f",dval);
            break;
         case 's':
            for(sval=va_arg(ap, char*);*sval;sval++)
               putchar(*sval);
            break;
         case 't' :
            tval=va_arg(ap, int);
            SetColor(tval,STD);
            break;
         case 'b' :
            bval=va_arg(ap, int);
            SetColor(STD,bval);
            break;
         default:
            putchar(*p);
            break;
      }
   }
   TextReset();
   va_end(ap);        //fa pulizia alla fine della funzione
}


         
