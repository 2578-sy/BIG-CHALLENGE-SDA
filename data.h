#ifndef DATA_H
#define DATA_H

// batas maksimum kata
#define MAX_WORDS 150000

// panjang maksimum kata
#define MAX_LENGTH 100

// struct penyimpanan kata dan frekuensi
typedef struct {
    char word[MAX_LENGTH];
    long long freq;
} WordData;

extern WordData data[MAX_WORDS];

#endif
