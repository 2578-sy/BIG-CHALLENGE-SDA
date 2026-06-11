#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "file_handler.h"

// array utama penyimpanan data
WordData data[MAX_WORDS];

// total kata vocabulary
int totalWords = 0;

// membaca file vocabulary
void loadVocabulary(char vocabFile[]) {

    FILE *fp;

    fp = fopen(vocabFile, "r");

    // cek file
    if (fp == NULL) {
        printf("File vocabulary tidak ditemukan!\n");
        return;
    }

    // mulai dari index 1
    totalWords = 1;

    // baca semua kata
    while (fgets(data[totalWords].word, MAX_LENGTH, fp) != NULL) {

        // hapus enter
        data[totalWords].word[strcspn(data[totalWords].word, "\n")] = '\0';

        // inisialisasi frekuensi
        data[totalWords].freq = 0;

        totalWords++;
    }

    fclose(fp);

    printf("Vocabulary berhasil dimuat.\n");
}

// membaca file docword
void loadDocword(char docwordFile[]) {

    FILE *fp;

    fp = fopen(docwordFile, "r");

    // cek file
    if (fp == NULL) {
        printf("File docword tidak ditemukan!\n");
        return;
    }

    int D;
    int W;
    int N;

    // baca header file
    fscanf(fp, "%d", &D);
    fscanf(fp, "%d", &W);
    fscanf(fp, "%d", &N);

    int docID;
    int wordID;
    int count;

    // baca data frekuensi
    while (fscanf(fp, "%d %d %d",
           &docID,
           &wordID,
           &count) == 3) {

        // tambah total frekuensi kata
        data[wordID].freq += count;
    }

    fclose(fp);

    printf("Frekuensi kata berhasil dihitung.\n");
}

// mengembalikan total kata
int getTotalWords() {

    return totalWords;
}
