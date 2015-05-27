#include "tree.h"
#include "../lib/stack/libstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*-----------------------------------------------------------------------------*
| Header contenente i prototipi delle funzioni per la gestione dell'albero.    |
|                                                                              |
|                                                                              |
| Data creazione: 22/12/2008            Autore: Cittadini Paolo e Arcadio Ciro |
*-----------------------------------------------------------------------------*/
//path: ./Tree/

/*[3x01]*/TREE *StackToTree (STACK **Stk, int *c);
/*[3x02]*/int  NewLeaf      (TREE **Tree);
/*[3x03]*/void HeightVisit  (TREE *Tree, int *c);
/*[3x04]*/int  LcOpen       (TREE **Tree);
/*[3x05]*/int  ReadClass    (FILE *lc, STACK **Stack);
/*[3x06]*/int  LoadLeaf     (FILE *lc, TREE **Tree);
/*[3x07]*/void StampaTree   (TREE *Tree,int h);
/*[3x08]*/void LeafsToStack (TREE **Tree, STACK **Leafs, int Height, int Level);
/*[3x09]*/void FreeTree     (TREE **Root);
