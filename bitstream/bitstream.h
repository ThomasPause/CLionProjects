//
// Created by thomas on 5/25/18.
//

#ifndef BITSTREAM_BITSTREAM_H
#define BITSTREAM_BITSTREAM_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {unsigned char* bitField; unsigned int len; unsigned int pos;} Bitstream;

void createBitstream (Bitstream* bs, unsigned int length);
void destroyBitstream (Bitstream* bs);
void writeToStream(Bitstream *bs, unsigned int bitcount, unsigned int value_dec);
unsigned int convertToBinary(unsigned int value_dec);

#endif //BITSTREAM_BITSTREAM_H
