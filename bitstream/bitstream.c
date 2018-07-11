//
// Created by thomas on 5/25/18.
//

#include "bitstream.h"

//Bitstream erstellen und (durch Calloc) mit 0en auffuellen
void createBitstream (Bitstream* bs, unsigned int length){
    bs->bitField = (unsigned char*) calloc(length, sizeof(unsigned char) * length);
    bs->len = length;
    printf("Ein Bitstream mit der Laenge %d wurde erstellt und mit Nullen aufgefuellt!!\n", length);
}
//Zerstoert den Bitstream, setzt Laenge und Position auf 0
void destroyBitstream (Bitstream* bs){
    free(bs->bitField);
    bs->len = 0;
    bs->pos = 0;
    printf("\nDer Bitstream wurde zerstoert!!\n");
}
//Umwandlung in binaer (mit Bitshift) und schreiben in den Bitstream
void writeToStream(Bitstream *bs, unsigned int bits, unsigned int value){
    //TODO Ausgabe basteln
    printf("Es wird in den Bitstream geschrieben...\n");
    unsigned int c, k;

    for(c = 0; c <= bits-1; ++c, ++(bs->pos)){
        k = value >> c;

        if(k & 1){
            bs->bitField[bs->pos] = 1;
        }
        else{
            bs->bitField[bs->pos] = 0;
        }
    }
}
//Hilfsmethode zum Umwandeln in binaer (arithmetisch)
/*unsigned int convertToBinary(unsigned int value_dec){
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
}*/
