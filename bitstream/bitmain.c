//
// Created by thomas on 5/25/18.
//

#include "bitstream.h"

int main(void) {

    Bitstream bs;
    createBitstream(&bs, 50);
    writeToStream(&bs, 3, 3);
    destroyBitstream(&bs);

    //Test der auskommentierten Hilfsmethode (zu Uebungszwecken)
    //printf("%d",convertToBinary(3));
}
