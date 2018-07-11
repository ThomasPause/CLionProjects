#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654

//Erzeuge struct Dreieck, welche die 3 Kantenlaengen als double speichert
struct Dreieck{
    double seiteA;
    double seiteB;
    double seiteC;
};
//Signaturen der zu implementierenden Funktionen
int testLaenge(struct Dreieck tri);
double umfang(struct Dreieck tri);
double flaeche(struct Dreieck tri);
double umkreisRadius(struct Dreieck tri);
double inkreisRadius(struct Dreieck tri);
double kosinussatz(double seiteC, double seiteA, double seiteB);
void winkel(struct Dreieck tri, double *alpha, double *beta, double *gamma);

/**
 * Main-Funktion, Einsprungpunkt des Programmes
 */
int main(void)
{
    struct Dreieck tri;
    double alpha, beta, gamma;

    printf("##################################################################\n"
           "Programm zur Berechnung charakteristischer Groessen eines Dreiecks\n"
           "##################################################################\n\n"
           "Geben Sie die Länge der Seiten a, b und c des Dreiecks an: \n");
    int success = scanf("%lf, %lf, %lf", &tri.seiteA, &tri.seiteB, &tri.seiteC);
    if (success != 3) {
        fprintf(stderr, "Fehler bei der Eingabe: Erwarte 3 doubles durch Komma "
                        "getrennt. Bitte nochmal!\n");
        return EXIT_FAILURE;
    }
    printf("Folgende Daten gelesen: a=%g, b=%g, c=%g\n", tri.seiteA, tri.seiteB,
           tri.seiteC);
    if (testLaenge(tri)==0){
        printf("Glueckwunsch!! Es handelt sich um ein gueltiges Dreieck!!\n");
    }
    else{
        fprintf(stderr, "Fehler!! Die eingegebenen Laengen bilden kein gueltiges Dreieck!!\n");
        return EXIT_FAILURE;
    }
    printf("Der Umfang des Dreiecks ist: %f\n", umfang(tri));
    printf("Die Fläche des Dreiecks ist: %f\n", flaeche(tri));
    printf("Der Umkreisradius des Dreiecks ist: %f\n", umkreisRadius(tri));
    printf("Der Inkreisradius des Dreiecks ist: %f\n", inkreisRadius(tri));
    winkel(tri, &alpha, &beta, &gamma);
    printf("Der Winkel alpha des Dreiecks ist: %f\n", alpha);
    printf("Der Winkel beta des Dreiecks ist: %f\n", beta);
    printf("Der Winkel gamma des Dreiecks ist: %f\n", gamma);

    return EXIT_SUCCESS;
}
//testet, ob die eingegebenen Seiten ein gueltiges Dreieck bilden (mit Dreiecksungleichung)
int testLaenge(struct Dreieck tri){
    if (((tri.seiteA+tri.seiteB)>=tri.seiteC) &&
        ((tri.seiteA+tri.seiteC)>=tri.seiteB) &&
        ((tri.seiteB+tri.seiteC)>=tri.seiteA)){
        return 0;
    }
    else {
        return 1;
    }
}
//berechnet den Umfang des Dreiecks
double umfang(struct Dreieck tri){
    double umfang = tri.seiteA + tri.seiteB + tri.seiteC;
    return umfang;
}
//berechnet den Flaecheninhalt des Dreiecks
double flaeche(struct Dreieck tri){
    double s = umfang(tri)/2;
    double flaeche = sqrt(s*(s-tri.seiteA)*(s-tri.seiteB)*(s-tri.seiteC));
    return flaeche;
}
//berechnet den Umkreis-Radius des Dreiecks
double umkreisRadius(struct Dreieck tri){
    double umkreisRadius = ((tri.seiteA*tri.seiteB*tri.seiteC)/4*flaeche(tri));
    return umkreisRadius;
}
//berechnet den Inkreis-Radius des Dreiecks
double inkreisRadius(struct Dreieck tri){
    double inkreisRadius = ((2*flaeche(tri))/umfang(tri));
    return inkreisRadius;
}
//Winkelberechnung ueber Kosinussatz
double kosinussatz(double seiteC, double seiteA, double seiteB){
    double cos = acos(((pow(seiteA, 2)+pow(seiteB, 2)-pow(seiteC, 2))/(2*seiteA*seiteB)));
    //Normalisierung auf grad
    return cos*180/PI;
}
//Rueckgabe aller Winkel unter Zuhilfenahme des Kosinussatzes ueber Pointer
void winkel(struct Dreieck tri, double *alpha, double *beta, double *gamma){
    *alpha = kosinussatz(tri.seiteA, tri.seiteB, tri.seiteC);
    *beta = kosinussatz(tri.seiteB, tri.seiteA, tri.seiteC);
    *gamma = kosinussatz(tri.seiteC, tri.seiteA, tri.seiteB);
}