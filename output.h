#ifndef OUTPUT_H
#define OUTPUT_H

#include "data.h"

/* Simpan hasil sorting ke file */
void saveToFile(
    char filename[],
    WordData data[],
    int totalWords,
    double timeTaken
);

/* Tampilkan Top-K ke layar */
void printTopK(
    WordData data[],
    int k
);

#endif
