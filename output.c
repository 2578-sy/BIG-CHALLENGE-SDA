#include <stdio.h>
#include "output.h"

/* =====================================
   Simpan hasil ke file
   ===================================== */

void saveToFile(
    char filename[],
    WordData data[],
    int totalWords,
    double timeTaken
)
{
    FILE *fp;

    fp = fopen(filename, "w");

    if(fp == NULL)
    {
        printf("Gagal membuat file output!\n");
        return;
    }

    int i;

    /* Karena data dimulai dari index 1 */
    for(i = 1; i <= totalWords; i++)
    {
        fprintf(
            fp,
            "%s (%lld)\n",
            data[i].word,
            data[i].freq
        );
    }

    fprintf(
        fp,
        "\nWaktu untuk mengurutkan : %.2f ms\n",
        timeTaken
    );

    fclose(fp);
}

/* =====================================
   Tampilkan Top-K
   ===================================== */

void printTopK(
    WordData data[],
    int k
)
{
    int i;

    if(k <= 0)
    {
        printf("Nilai k tidak valid!\n");
        return;
    }

    for(i = 1; i <= k; i++)
    {
        printf(
            "%s (%lld)\n",
            data[i].word,
            data[i].freq
        );
    }
}
