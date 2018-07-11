//
// Created by thomas on 5/16/18.
//

#include "intarray.h"

//erzeugen des IntArray mit gegebener Laenge
void create( IntArray* ia, unsigned int len){
    ia->field = (int*) malloc(sizeof(int)* len);
    ia->length = len;
}
//zerstoeren des IntArray und freigeben des Speichers
void destroy(IntArray* ia){
    free(ia->field);
    ia->length = 0;
    printf("\nDas IntArray wurde zerstoert!!\n\n");
}
//auslesen eines Wertes an einer bestimmten Position
int read(IntArray* ia, unsigned int position){
    if (position>=ia->length){
        fprintf(stdout, "Fehler!! Ausserhalb von IntArray (hier an Position %d) kann nix gelesen werden!\n"
                        "Das IntArray hat nur die Groesse %d", position, ia->length);
        return EXIT_FAILURE;
    }
        printf("\nDer Wert an der Stelle %d ist: %d\n", position, ia->field[position]);
        return EXIT_SUCCESS;

}
//setzen/einlesen eines bestimmten Wertes an einer bestimmten Position
int set(IntArray* ia, unsigned int position, int wert){
    if (position>=ia->length){
        fprintf(stdout, "Fehler!! Ausserhalb von IntArray (hier an Position %d) kann nix gesetzt werden!\n"
                        "Das IntArray hat nur die Groesse %d\n", position, ia->length);
        return EXIT_FAILURE;
    }
        ia->field[position] = wert;
        printf("Der Wert %d wurde an der Position %d eingefuegt!\n", wert, position);
        return EXIT_SUCCESS;
}
