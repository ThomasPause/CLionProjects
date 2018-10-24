//
// Created by thomas on 5/16/18.
//

#ifndef INTARRAY_INTARRAY_H
#define INTARRAY_INTARRAY_H

#include <stdlib.h>
#include <stdio.h>

//Struktur aus einem Feld von Ganzzahlen und dessen Laenge
typedef struct {int* field; unsigned int length;} IntArray;

void create(IntArray* ia, unsigned int len);
void destroy(IntArray* ia);
int read(IntArray* ia, unsigned int position);
int set(IntArray* ia, unsigned int position, int wert);

#endif //INTARRAY_INTARRAY_H
