//
// Created by thomas on 3/28/18.
//
#include <stdio.h>
#include <stdlib.h>
/*void add( int a, int b) {
    a += b;
}
void sub( int *a, int* b) {
    *a -= *b;
}
void mul( int a, int *b) {
    a *= *b;
}
void div( int *a, int b) {
    *a /= b;
}*/


    //Alternative
    /*void rechtschreibmod(char *satz){
        for (int i = 0; satz[i] != '\0'; ++i){
            if (satz[i] == 'p' && satz[i+1] == 'h'){
                satz[i] = 'f';
                for (int j = i+1; satz[j] != '\0'; ++j){
                    char temp = satz[j];
                    char temp2 = satz[j + 1];
                    satz[j] = satz[j + 1];
                }
            }
        }
    }*/
    //vorherige Deklaration der Methode
/*void rechtschreibmod(char *);
    int main() {
        //Test rechtschreibmod()
        char satz[] = "PHysioterapheutische philosophische Phielphalt";
        rechtschreibmod(satz);
        printf("%s", satz);
    }*/

typedef struct {
    double re;
    double im;
}Complex;

Complex complex_mult(const Complex * const x, const Complex * const y){
    double a =x->re;
    double b = x->im;
    double c = y->re;
    double d = y->im;

    Complex result;
    result.re=(a*c-b*d);
    result.im=(b*c+a*d);
    return result;
}
void geradeUngerade(int i){
    switch (i%2){
        case 0: printf("gerade");break;
        default:printf("ungerade");
    }
}
//Aufgaben aus der MuP2-Klausur
int main () {
   /* for (int i = 0; i<5; i++){
        printf("%i ist ", i);
        geradeUngerade(i);
        printf("\n");
    }*/

    Complex test;
    test.re=5;
    test.im=10;
    Complex test2;
    test2.re=8;
    test2.im=11;

    Complex erg=complex_mult(&test,&test2);
    printf("%f, %f", erg.re, erg.im);
    /*int *array;
    int size = 10;
    array = malloc(sizeof(int) * size);
    int i = 0;
    while (i < size) {
        array[i] = i;
        printf("%d\n", i);
        i++;
    }
    free(array);
}*/

    /*char text[] = "56789";
    int zahlen[] = {1,2,3,4,5};
    for( unsigned int i = 0 ; i < sizeof(text) - 1 ; i++) {
        zahlen[i] = (int)text[i];
    }
    printf( "%f\n", zahlen[3] );*/
/*
int a = 2, b = 3;

    sub( &a, &a );
    add( a, b );
    div( &a, b );
    mul( b, &a );
    div( &b, b );
    add( b, a );
        printf( "%d\n", a ); // Ausgabe?:
        printf( "%d\n", b ); // Ausgabe?:

    char x[] = "Hallo Welt!";
    char *y = x + 6;
    printf("%c\n", *(--y + 1));
    printf("%c\n", y[-4]);
    printf("%c\n", *(x + 2));
    printf("%c\n", x[(y - x) * 2 - 3]);
    printf("%ld\n", (x - y++));

    return 0;
}
*/



/*
void rechtschreibmod(char *satz) {
    for (int i = 0; *(satz + i) != '\0'; ++i) {
        if ((*(satz + i) == 'p' || *(satz + i) == 'P') &&
            (*(satz + i + 1) == 'h' || *(satz + i+ 1) == 'H')) {
            *(satz + i) = 'f';
            //satz[i + 1] = NULL;
            for (int j = i + 1; *(satz + j) != '\0'; ++j) {
                char temp = *(satz + j);
                char temp2 = *(satz + (j + 1));
                *(satz + j) = *(satz + (j + 1));
            }
        }
    }
}
*/}
