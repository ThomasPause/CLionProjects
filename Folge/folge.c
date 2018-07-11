//
// Created by thomas on 5/26/18.
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//rekursive Darstellung einer gegebenen Zahlenfolge
double recursive (unsigned int n){
    if (n>0){
        //gibt das n-te Folgenglied nach der Bildungsvorschrift zurueck
        double result = 0.6 * (1 - (pow(-0.5, n)));
        printf("Der Wert fuer n=%d ist: %f\n", n, result);
        //rekursiver Aufruf, n wird auf n-1 gesetzt
        recursive(n-1);
        return result;
    }else{
        //gibt 0 zurueck, falls n 0 ist
        double result = 0;
        printf("Der Wert fuer n=%d ist: %f\n", n, result);
        return result;
    }
}
int main(void){
    //Eingabe der Rekursionsschritte n
    int n = 1;
    //abfangen des falls, dass n negativ ist (ginge auch gleich mit unsigned int)
    if (n < 0){
        fprintf(stderr, "Die Anzahl der Rekursionsschritte n muss positiv sein!!");
        return EXIT_FAILURE;
    }
    recursive(n);
    return EXIT_SUCCESS;
}