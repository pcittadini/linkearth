#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
/*-----------------------------------------------------------------------------*
| Header contenente definizioni di struttura del GRAFO.                        |
|                                                                              |
|                                                                              |
| Data creazione: 22/12/2008            Autore: Cittadini Paolo e Arcadio Ciro |
*-----------------------------------------------------------------------------*/
#define  BATCH_NODE 16
#ifndef _BOOLEAN_TYPE_ //se non è definito il tipo booleano
#define _BOOLEAN_TYPE_ //definisce enumerazione tipo
typedef enum {false,true}boolean;
#endif

#ifndef _GRAPH_STRUCT_H_ //se la struttura è indefinita da predente linking
#define _GRAPH_STRUCT_H_ //definisci il codice seguente
/*-----------------------------------------------------------------------------*
| definizione della struttura ARCO di un NODO                                  |
*-----------------------------------------------------------------------------*/
struct ARK{                                //ARCO 
            double KmDist;                 //Lunghezza in KM dell'ARCO  (Peso)     
            int IDLinkedNode;              //id nodo collegato
            struct ARK *NextArk;           //Link al prossimo arco del nodo
          };
typedef struct ARK ARK;
/*-----------------------------------------------------------------------------*
| definizione della struttura NODO del GRAFO                                   |
*-----------------------------------------------------------------------------*/
struct GRAPH_NODE{                         //NODO
                     TREE *Node;           //LINK di tipo TREE
                     ARK *Ark;             //archi del nodo (LISTA DI ARCHI)
                     int Visited;          //flag di NODO visitato
                 };
typedef struct GRAPH_NODE GRAPH_NODE;
/*-----------------------------------------------------------------------------*
| definizione della struttura GRAFO                                            |
*-----------------------------------------------------------------------------*/
struct GRAPH{                              //GRAFO
               int TotNodes;               //nodi in totale
               int MaxAllocNode;           //nodi liberi prima di realloc
               GRAPH_NODE *StartNode;      //puntatore al primo nodo
            };
typedef struct GRAPH GRAPH;
#endif
              
