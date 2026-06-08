#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

// batas maksimum kata
#define MAX_WORDS 150000

// panjang maksimum kata
#define MAX_LENGTH 100

// struct data kata dan frekuensi
typedef struct {
    char word[MAX_LENGTH];
    long long freq;
} WordData;

// array global data kata
extern WordData data[MAX_WORDS];

// membaca file vocabulary
void loadVocabulary(char vocabFile[]);

// membaca file docword
void loadDocword(char docwordFile[]);

// mengambil total kata
int getTotalWords();

#endif
