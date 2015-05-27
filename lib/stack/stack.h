#include <stdio.h>
#include <stdlib.h>
/*-----------------------------------------------------------------------------*
| Header contenente la definizione di struttura dello STACK.                   |
|                                                                              |
|                                                                              |
| Data creazione: 22/12/2008            Autore: Cittadini Paolo e Arcadio Ciro |
*-----------------------------------------------------------------------------*/
#ifndef _TREE_STRUCT_H_        //se la struttura Albero Binario non è definita
#include "../../include/tree.h"//include l'header che ne contiene la definizione
#endif

#ifndef _STACK_STRUCT_H_       //se la struttura STACK è indefinita
#define _STACK_STRUCT_H_       //definisce il codice della struttura
struct stack{
               TREE  *Item;        //campo "Info" di tipo TREE
               struct stack *Next; //puntatore all'elemento successivo
	         };
		    
typedef struct stack STACK;        //definizione di tipo 

#ifndef _BOOLEAN_TYPE_             //se il tipo booleano è indefinito
#define _BOOLEAN_TYPE_             //definisci il tipo booleano
typedef enum {false,true}boolean;
#endif

#endif

