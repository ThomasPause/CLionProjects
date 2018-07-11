#include "fibonacci.h"
//
// Created by thomas on 4/15/18.
//


unsigned long long fib(int n){
    int i;
    unsigned long long fi;
    unsigned long long f1=0;
    unsigned long long f2=1;

    if( n == 0){  // das 0. Folgenglied ist per Definition 0
        return 0;
    }
    if( n == 1){  // das 1. Folgenglied ist per Definition 1
        return 1;
    }
    for (i = 2; i<=n; i++){
        fi=f1+f2;
        f1=f2;
        f2=fi;
    }

   /**
    * rekursiv waere der  letzte Punkt wie folgt:
    * if( n > 1){   // alle weiteren Folgenglieder werden aus den jeweiligen Vorgaengern berechnet
    * return fib(n-1)+fib(n-2);}
    */
    return fi;
}



