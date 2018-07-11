#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
    double a = 0, b = 0, c = 0, d, p, q;

    printf("Nullstellen der quadratischen Gleichung ax^2+bx+c=0\n");
    printf("Bitte geben Sie a, b, c ein: \n");
    int success = scanf("%lf, %lf, %lf", &a, &b, &c);
    if (success != 3) {
        fprintf(stderr, "Fehler bei der Eingabe. Bitte geben Sie a,b und c "
                        "nochmals mit Komma getrennt ein.\n");
        return EXIT_FAILURE;
    }
/*
 * ax^2+bx+c=0
 * Normalform wenn a=1, dahin gelangt man durch die schritte:
 * p=b/a und q=c/a
 * Normalform dann x^2+px+q=0
 * Wieviele Lsg die Gleichung hat, bestimmt die Diskriminante D
 * D=p^2-4q
 * D>0 --> es gibt 2 reelle NS
 * D=0 --> es gibt 1 reelle NS
 * D<0 --> es gibt keine reelle NS
 * Loesung durch p-q-formel:
 * -p/2 +- sqrt((p/2)^2-q)
 *
 */
    p=b/a;
    q=c/a;
    d=p*p-4*q;
    if (d>0){
        printf("Es gibt 2 reelle Nullstellen!\n");
        double x1=-p/2 + sqrt(pow(p/2, 2)-q);
        double x2=-p/2 - sqrt(pow(p/2, 2)-q);
        printf("X1 ist %lf\n", x1);
        printf("X2 ist %lf\n", x2);
    }
    if (d==0){
        printf("Es gibt 1 reelle Nullstelle!\n");
        double x=-p/2 + sqrt(pow(p/2, 2)-q);
        printf("X ist %lf\n", x);
    }
    if (d<0){
        printf("Es gibt keine reellen Nullstellen! Schaaade..\n");
        return EXIT_SUCCESS;
    }
    return EXIT_SUCCESS;
}
