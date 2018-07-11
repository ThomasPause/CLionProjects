#include <stdlib.h>
#include <stdio.h>

//
// Created by thomas on 4/27/18.
//
unsigned long long fib(int);    //ull macht hier mehr sinn als int, weil es sonst schon bei der 47.Zahl zum overflow kommt

int main() {
    /**
     * Die zu berechnende Fibonacci-Zahl n soll als Konstante in der main angegeben werden
     * also bitte hier eingeben!!
     */
    const int n=42;

    printf("Programm zur Berechnung von Fibonacci-Zahlen\n"
           "********************************************\n");
    //Ausgabe Fehler, falls n negativ ist
    if (n<0){
        printf("Die eingegebene Zahl darf nicht kleiner als 0 sein");
        return (EXIT_FAILURE);
    }else{
        //Ausgabe des Ergebnisses von fib(n), falls n>=0
        unsigned long long result= fib(n);
        printf("Die %d. Fibonacci-Zahl ist:\n", n);
        printf("%llu", result);

        return (EXIT_SUCCESS);}
}


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
    return fi;
}
