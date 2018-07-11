//
// Created by thomas on 5/25/18.
//

#include "intarray.h"

int main(void) {

    //Test des IntArray-Tools

    IntArray ia;
    unsigned int length=10;
    //Erzeugen eines IntArray der Groesse 10
    create(&ia, 10);
    //Setzen "zufaelliger" Werte in den einzelnen Indizes
    for (unsigned int i = 0; i<length; i++){
        set(&ia, i, rand()%100);
    }
    //Lesen und Ausgabe des Wertes an Position 5
    read(&ia, 5);
    //Zerstoeren des IntArray
    destroy(&ia);
    //Test, ob wirklich geloescht wurde
    read(&ia, 5);

    return EXIT_SUCCESS;
}