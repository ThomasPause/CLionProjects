//
// Created by thomas on 4/15/18.
//
#include "fibonacci.h"

/**
 * ich habe die Funktionalitaet in eine eigene C-Datei ausgelagert und den zugehoerigen Header
 * (der auch alle includes fuer main und fibonacci enthaelt) in die main inkludiert
 */

int main() {
    //Zeitmessung
    clock_t start =  clock();

    /**
     * Die zu berechnende Fibonacci-Zahl n soll als Konstante in der main angegeben werden
     * also bitte hier eingeben!!
     */
    const int n=88;

        printf("Programm zur Berechnung von Fibonacci-Zahlen\n"
               "********************************************\n");
        //Ausgabe Fehler, falls n negativ ist
        if (n<0){
            printf("Die eingegebene Zahl darf nicht kleiner als 0 sein");
            return (EXIT_FAILURE);
        }else{
        //Ausgabe des Ergebnisses von fib(n), falls n>=0
            unsigned long long result=(unsigned long long) fib(n);
            printf("Die %d. Fibonacci-Zahl ist:\n", n);
            printf("%llu", result);

            clock_t ende = clock();
            double diff = (double)(ende-start) / (CLOCKS_PER_SEC/1000);
            printf("\n\nRechenzeit: %g ms", diff);
        return (EXIT_SUCCESS);}
}