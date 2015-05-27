#include <stdio.h>
#include <stdlib.h>
/*-----------------------------------------------------------------------------*
| Header contenente la definizione di struttura dell'albero binario.           |
|                                                                              |
|                                                                              |
| Data creazione: 22/12/2008            Autore: Cittadini Paolo e Arcadio Ciro |
*-----------------------------------------------------------------------------*/

#ifndef _TREE_STRUCT_H_  //se non definita da un linking precedente
#define _TREE_STRUCT_H_  //definisci il seguente codice 

#ifndef BUFFSIZE
#define BUFFSIZE 128     //buffer di lettura caratteri 
#endif

typedef struct TREE {
                        char  City[BUFFSIZE];//campo CITTA
                        int   Region;        //campo regione geodetica
                        double Lat;          //campo latitudine
                        double Long;         //campo longitudine
                        struct TREE *Left;   //figlio Sx
                        struct TREE *Right;  //figlio Dx
                    } TREE;
#endif
