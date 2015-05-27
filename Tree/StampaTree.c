#include "../include/libtree.h"
#include <math.h>
void StampaTree
(
   TREE* Tree,
   int h
)
{
   int i,j,c;
   long numl;
   int lev;
   int met;
   int space;
   int drift;
   long attl;
   
   FILE *out;
   out=fopen("tree.txt","w");
   c=0;
    
   lev=log2(h);
   for(;lev>0;lev--)
   {
      numl=pow(2,lev);
      met=(numl/2);
      if(met!=1)
         space=(5*(met/2))+(met/2);
      else
         space=3;
      drift=space;
      space=drift/2;
      drift=drift-space;
      
      attl=pow(2,c);
      for(j=0;j<attl;j++)
      {
         for(i=0;i<space;i++)
            fputs(" ",out);
         for(i=0;i<drift;i++)
            fputs("_",out);
         fputs("O",out);
         for(i=0;i<drift;i++)
            fputs("_",out);
         for(i=1;i<space;i++)
            fputs(" ",out);
      }
      fputs("\n",out);
      if(lev>1)
         for(j=0;j<(attl*2);j++)
         {
            for(i=0;i<space;i++)
               fputs(" ",out);
            fputs("|",out);
            for(i=0;i<space-1;i++)
               fputs(" ",out);
         }
      else
      {
      for(j=0;j<attl;j++)
         fputs(" |   |",out);
      fputs("\n",out);
      for(j=0;j<attl;j++)
         fputs(" O   O",out);
      }
      fputs("\n",out);
      c++;  
   }
   fclose(out);
}
