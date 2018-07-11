//
// Created by thomas on 3/28/18.
//
#include <stdio.h>
    void add( int a, int b) {
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
    }


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
void rechtschreibmod(char *);
    int main(){
        //Test rechtschreibmod()
        char satz[] = "philosoph";
        rechtschreibmod(satz);
        printf("%s", satz);

        //Aufgaben aus der MuP2-Klausur
        /*int a = 2, b = 3;
        //a = 0, b = 3
        sub( &a, &a );
        //a = 0, b = 3
        add( a, b );
        //a = 0, b = 3
        div( &a, b );
        //a = 0, b = 3
        mul( b, &a );
        //a = 0, b = 1
        div( &b, b );
        add( b, a );
        printf( "%d\n", a ); // Ausgabe?:
        printf( "%d\n", b ); // Ausgabe?:

        char x[] = "Hallo Welt!";
        char *y = x + 6;
        printf( "%c\n", *( --y + 1 ) );
        printf( "%c\n", y[-4] );
        printf( "%c\n", *( x + 2 ) );
        printf( "%c\n", x[( y - x ) * 2 - 3] );
        printf( "%ld\n", ( x - y++ ) );*/


        return 0;
    }

void rechtschreibmod(char *satz){
    for (int i = 0; *(satz+i) != '\0'; ++i){
        if (*(satz+i) == 'p' && *(satz + i + 1) == 'h'){
            *(satz+i) = 'f';
            //satz[i + 1] = NULL;
            for (int j = i+1; *(satz+j) != '\0'; ++j){
                char temp = *(satz + j);
                char temp2 = *(satz + (j + 1));
                *(satz + j) = *(satz + (j + 1));
            }
        }
    }
}