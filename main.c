#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file_handler.h"
#include "sorting.h"
#include "output.h"
#include "data.h"

// menampilkan menu
void menu() {

    printf("\n");
    printf("=====================================\n");
    printf(" BIG CHALLENGE STRUKTUR DATA\n");
    printf("=====================================\n");
    printf("1. Insertion Sort\n");
    printf("2. Quick Sort\n");
    printf("3. Heap Sort\n");
    printf("4. Tampilkan Top-K\n");
    printf("5. Keluar\n");
    printf("=====================================\n");
    printf("Pilihan anda : ");
}

int main() {

    int dataset;
    int choice;
    int k;

    clock_t start;
    clock_t end;

    double timeTaken;

    // pilih dataset
    printf("Pilih dataset:\n");
    printf("1. KOS\n");
    printf("2. NIPS\n");
    printf("3. ENRON\n");
    printf("4. NYTIMES\n");
    printf("5. PUBMED\n");
    printf("Pilihan anda : ");
    scanf("%d", &dataset);

    // load dataset sesuai pilihan
    switch(dataset) {

        case 1:
            loadVocabulary("vocab.kos.txt");
            loadDocword("docword.kos.txt");
            break;

        case 2:
            loadVocabulary("vocab.nips.txt");
            loadDocword("docword.nips.txt");
            break;

        case 3:
            loadVocabulary("vocab.enron.txt");
            loadDocword("docword.enron.txt");
            break;

        case 4:
            loadVocabulary("vocab.nytimes.txt");
            loadDocword("docword.nytimes.txt");
            break;

        case 5:
            loadVocabulary("vocab.pubmed.txt");
            loadDocword("docword.pubmed.txt");
            break;

        default:
            printf("Pilihan tidak valid!\n");
            return 0;
    }

    // menu utama
    do {

        menu();

        scanf("%d", &choice);

        switch(choice) {

            case 1:

                start = clock();

                insertionSort(data, getTotalWords());

                end = clock();

                timeTaken =
                ((double)(end - start))
                / CLOCKS_PER_SEC * 1000;

                saveToFile(
                    "output_insertion.txt",
                    data,
                    getTotalWords(),
                    timeTaken
                );

                printf("Hasil berhasil disimpan.\n");
                printf("Waktu sorting : %.2f ms\n",
                       timeTaken);

                break;

            case 2:

                start = clock();

                quickSort(
                    data,
                    0,
                    getTotalWords() - 1
                );

                end = clock();

                timeTaken =
                ((double)(end - start))
                / CLOCKS_PER_SEC * 1000;

                saveToFile(
                    "output_quicksort.txt",
                    data,
                    getTotalWords(),
                    timeTaken
                );

                printf("Hasil berhasil disimpan.\n");
                printf("Waktu sorting : %.2f ms\n",
                       timeTaken);

                break;

            case 3:

                start = clock();

                heapSort(
                    data,
                    getTotalWords()
                );

                end = clock();

                timeTaken =
                ((double)(end - start))
                / CLOCKS_PER_SEC * 1000;

                saveToFile(
                    "output_heapsort.txt",
                    data,
                    getTotalWords(),
                    timeTaken
                );

                printf("Hasil berhasil disimpan.\n");
                printf("Waktu sorting : %.2f ms\n",
                       timeTaken);

                break;

            case 4:

                printf("Masukkan nilai k : ");
                scanf("%d", &k);

                start = clock();

                quickSort(
                    data,
                    0,
                    getTotalWords() - 1
                );

                end = clock();

                timeTaken =
                ((double)(end - start))
                / CLOCKS_PER_SEC * 1000;

                printTopK(data, k);

                printf("\nWaktu sorting : %.2f ms\n",
                       timeTaken);

                break;

            case 5:

                printf("Program selesai.\n");

                break;

            default:

                printf("Pilihan tidak valid!\n");
        }

    } while(choice != 5);

    return 0;
}
