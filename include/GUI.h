#include "../lib/platform/platform.h"
#include "../lib/stack/stack.h"
#include "tree.h"
#include "graph.h"
/*-----------------------------------------------------------------------------*
| Header file contenente le definizioni e la configurazione della GUI          |
|                                                                              |
|                                                                              |
| Data creazione: 22/12/2008            Autore: Cittadini Paolo e Arcadio Ciro |
*-----------------------------------------------------------------------------*/
//Layouts dei Menu
#define MenuMAIN        0
#define MenuTREE        1
#define MenuGRAPH       2
#define MenuGRAPH_MOD   3
#define MenuGRAPH_MOD_A 4
#define MenuGRAPH_MOD_H 5
#define MenuGRAPH_MOD_D 6
#define MenuGRAPH_PATH  7
#define MenuOPT         8

//fine definizioni

extern int BKGRND;   // colore di background
extern int TXT;      // colore testo
extern int HBKGRND;  // colore evidenziatore
extern int HTXT;     // colore testo evidenziato

/*[3x25]*/void Splash         ();
/*[3x26]*/void DispBackground ();                                               
/*[3x27]*/void _DispBackground();
/*[3x28]*/void DispPopup      ();
/*[3x29]*/void DispForeground (int MenuID, int i);
/*[3x30]*/void DispTree       (TREE *Root, int i, int j, int Level);
/*[3x31]*/void DispGraph      (GRAPH *Grafo, int i, int j, int ArkNum);
/*[3x32]*/void DispBar        (int x,int y, int Max, int Actual);

/*[3x33]*/void MenuTree      (STACK**);
/*[3x34]*/void MenuTree_View (TREE* Root,TREE* Tree,int i,int j,int Level,int Begin,int*End);
/*[3x35]*/void MenuTree_Level(TREE* Tree, int Height, int *Level);
/*[3x36]*/void MenuGraph             (GRAPH *Grafo);
/*[3x37]*/void MenuGraph_View        (GRAPH *Grafo);
/*[3x38]*/void MenuGraph_Mod         (GRAPH *Grafo);
/*[3x39]*/void MenuGraph_Mod_LD      (GRAPH *Grafo);
/*[3x40]*/void MenuGraph_Mod_AddNode (GRAPH *Grafo);
/*[3x41]*/void MenuGraph_Mod_Ark     (GRAPH *Grafo);
/*[3x42]*/void MenuGraph_Mod_Hub     (GRAPH *Grafo);
/*[3x43]*/void MenuGraph_Mod_Delete  (GRAPH *Grafo);
/*[3x44]*/void MenuGraph_Path        (GRAPH *Grafo);
/*[3x45]*/void MenuGraph_Path_View   (GRAPH *Grafo, int *Steps, int Dim);
/*[3x46]*/void MenuOption    ();
/*[3x23]*/void GetConf        ();
/*[3x24]*/void SetConf        ();
/*[2x15]*/char   *GetchInLine  (int c,int line);
/*[2x16]*/char   *GetNumInLine (int c,int line);
