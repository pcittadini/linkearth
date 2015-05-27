#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
/*-----------------------------------------------------------------------------*
| Header contenente le funzioni per la gestione dello STACK.                   |
|                                                                              |
|                                                                              |
| Data creazione: 22/12/2008            Autore: Cittadini Paolo e Arcadio Ciro |
*-----------------------------------------------------------------------------*/
//path: ./lib/stack/
/*[stackx01]*/void     Init_STACK (STACK**       );
/*[staclx02]*/void     Push_STACK (TREE*, STACK**);
/*[stackx03]*/TREE*    Pop_STACK  (STACK**       );
/*[stackx04]*/void     Free_STACK (STACK**       );
/*[stackx05]*/boolean  Empty_STACK(STACK**       ); 

