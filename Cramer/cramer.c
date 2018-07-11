//
// Created by thomas on 5/5/18.
//
#include <stdlib.h>
#include <stdio.h>

/**
 * a*x + b*y = e
 * c*x + d*y = f
 * Loesung durch Determinantenbestimmung wie folgt:
 * x=((e*d)-(b*f)) / (det)
 * y=((a*f)-(e*c)) / (det)
 * Determinante det=(a*d)-(b*c)
 */
double cramerX(double b, double d, double e, double f, double det) {
        double x = ((e * d) - (b * f)) / det;
        return x;
}

double cramerY(double a, double c, double e, double f, double det) {
        double y = ((a * f) - (e * c)) / det;
        return y;
}
int main(void) {
    double a, b, c, d, e, f;
    printf("#################################################################\n"
               "Programm zur Loesung von Gleichungssystemen nach der Cramer-Regel\n"
               "#################################################################\n"
               "Loesung eines Gleichungssystems der Form:\n"
               "aX + bY = e\n"
               "cX + dY = f\n");
    printf("Bitte a, b, c, d, e und f eingeben:\n");
    int in = scanf("%lf, %lf, %lf, %lf, %lf, %lf", &a, &b, &c, &d, &e, &f);
    if (in != 6) {
        fprintf(stderr, "Falsche Eingabe! Erwarte 6 double-Werte mit Komma getrennt!\n"
                        "Bitte erneut probieren!");
        return EXIT_FAILURE;
    }
    printf("Ihre eingegebenen Werte:\na:%lf b:%lf c:%lf\nd:%lf e:%lf f:%lf\n", a, b, c, d, e, f);

    //Berechung der Determinante, die wenn sie 0 wird, eine Division durch 0 ausloesen wuerde
    double det=((a*d)-(b*c));
    //Abfangen dieses Falles
    if (det != 0) {
        double ergx = cramerX(b, d, e, f, det);
        double ergy = cramerY(a, c, e, f, det);
        printf("\n\n"
               "Das Ergebnis fuer X ist: %lf\n", ergx);
        printf("Das Ergebnis fuer Y ist: %lf\n", ergy);

        return EXIT_SUCCESS;
    }
    else{
        fprintf(stderr, "Eine Berechnung ist nicht moeglich!!");
        return EXIT_FAILURE;
    }
}