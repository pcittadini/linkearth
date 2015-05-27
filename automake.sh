#!/bin/bash

if [ "${1}" == "start" ];
then
   cc -Wall -g -pg -o linkEarth  LinkEarth.c lib/stack/STACK.c lib/platform/*.c Graph/*.c Tree/*.c GUI/*.c Gestione/*.c -D_GNU_SOURCE -lm
else

   echo "automake --usage 
         $ bash automake.sh start"
fi

