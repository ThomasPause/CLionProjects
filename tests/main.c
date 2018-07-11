#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void myAdd( int *a, int b ) {
   *a += b;
}
void mySub( int *a, int *b ) {
    *a -= *b;
}
void myMul( int a, int *b ) {
    *b *= a;
}
void myDiv( int a, int b ) {
    b /= a;
}
*/
unsigned int convertToBinary(unsigned int value_dec){
    unsigned int value_bin=0, temp, value_temp;
    unsigned int position = 1;
    value_temp = value_dec;
    while (value_temp > 0){

        temp=value_temp % 2;

        value_bin = (temp * position) + value_bin;
        value_temp /= 2;
        position *=10;

    }
    return value_bin;
}
int main (void) {

    printf("%d", convertToBinary(510));
   /* char wort[] = {'H', 'a', 'u', 's'};
    char wort_mit_Endzeichen[] = {'H', 'a', 'u', 's','\n'};
    char zeichenkette[] = "haus";
    char zeichenkette_mit_Endzeichen[] = "haus\0";

    printf("%d\n", strlen(wort));
    printf("%d\n", strlen(wort_mit_Endzeichen));
    printf("%d\n", strlen(zeichenkette));
    printf("%d\n", strlen(zeichenkette_mit_Endzeichen));
    char wort2[] = {'H', 'a', 'u', 's', '\n'};
    char zeichenkette2[] = "haus";
    printf("%d\n", strlen(wort2));
    printf("%d\n", strlen(zeichenkette2));*/



    /* int *a = malloc(sizeof(int));
     int *b = malloc(sizeof(int));
     int c = 3;
     *a = 1;
     *b = 2;
     myAdd(a, *b);
     mySub(&c, b);
     myMul(*b, &c);
     myDiv(*a, c);
     myAdd(&c, *b - *a);
     mySub(b, a);
     myMul(*a, a);
     myDiv(c, *b);
     printf("%d\n", *a);     //9
     printf("%d\n", *b);     //-1
     printf("%d\n", c);      //1
     free(a);
     free(b);*/

    /*char txt[] = "howdoyouturnthison";
    char *ptr = &txt[5];
    printf("%c\n", *ptr);               //y
    printf("%c\n", *++ptr);             //o
    printf("%c\n", *ptr++);             //o
    printf("%p\n", (void *) ++ptr);     //0x7ffd1a68cd98
    printf("%c\n", (ptr + 7)[-2]);      //h
    printf("%c\n", *(ptr + 8));         //o
    printf("%c\n", txt[4]);             //o
    printf("%p\n", (void *) &ptr[-2]);  //0x7ffd1a68cd96
    printf("%lx\n", &ptr[7] - txt);     //f
    printf("%c\n", ++(*ptr));           //u
    printf("%c\n", *&(--ptr)[4]);       //n
    printf("%p\n", (void *) txt);       //0x7ffd1a68cd90
    printf("%c\n", txt[0] + 1);         //i
    printf("%c\n", ptr[10]);            //n
    printf("%p\n", (void *) ptr);       //0x7ffd1a68cd97
    printf("%c\n", --(*(--ptr - 3)));   //c*/
}