//
// Created by thomas on 4/18/18.
//

#include "binokoeffi.h"

int bino(int n, int k){
    int i, erg;
    if (k==0){
        return 1;}

    else if ((2*k)>n){
        k=n-k;}

        erg=1;

    for (i=1; i<=k; i++){
            erg = erg * (n - k + i) / i;
        }
        return erg;
    }

