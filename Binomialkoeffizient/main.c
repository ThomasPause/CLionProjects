//
// Created by thomas on 4/18/18.
//
#include "binokoeffi.h"

int main() {

    const int n,k;
    printf("Programm zur Berechnung des Binomialkoeffizienten\n"
           "*************************************************\n"
           "Bitte n und k eingeben (getrennt durch Leerzeichen):\n");
    scanf("%d %d", &n, &k);

    int bin = bino(n, k);
    printf("Der Binomialkoeffizient (%d ueber %d) betraegt: %d", n, k, bin);

    return 0;
}