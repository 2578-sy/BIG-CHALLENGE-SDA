#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file_handler.h"
#include "sorting.h"
#include "output.h"
#include "data.h"

// Fungsi untuk membersihkan buffer input jika user salah ketik huruf
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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

    // pilih dataset dengan validasi error input huruf
    while (1) {
        printf("Pilih dataset:\n");
        printf("1. KOS\n");
        printf("2. NIPS\n");
        printf("3. ENRON\n");
        printf("4. NYTIMES\n");
        printf("5. PUBMED\n");
        printf("Pilihan anda : ");
        
        // Jika scanf mengembalikan nilai != 1, artinya yang dimasukkan bukan angka
        if (scanf("%d", &dataset) != 1) {
            printf("\nError: Masukkan harus berupa angka!\n\n");
            clearBuffer(); // Bersihkan huruf yang tertinggal di buffer
            continue;      // Ulangi lagi minta input dataset
        }

        if (dataset >= 1 && dataset <= 5) {
            break; // Input valid, keluar dari loop dataset
        } else {
            printf("\nPilihan tidak valid! Silakan pilih 1-5.\n\n");
        }
    }

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
    }

    // menu utama
    do {
        menu();

        // Validasi input menu jika user memasukkan huruf
        if (scanf("%d", &choice) != 1) {
            printf("\nError: Pilihan harus berupa angka!\n");
            clearBuffer(); // Bersihkan buffer supaya tidak infinite loop
            choice = 0;    // Reset choice agar memicu default case/mengulang loop dengan aman
            continue;
        }

        switch(choice) {
            case 1:
                start = clock();
                insertionSort(data, getTotalWords());
                end = clock();

                timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

                saveToFile("output_insertion.txt", data, getTotalWords(), timeTaken);
                printf("Hasil berhasil disimpan.\n");
                printf("Waktu sorting : %.2f ms\n", timeTaken);
                break;

            case 2:
                start = clock();
                quickSort(data, 0, getTotalWords() - 1);
                end = clock();

                timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

                saveToFile("output_quicksort.txt", data, getTotalWords(), timeTaken);
                printf("Hasil berhasil disimpan.\n");
                printf("Waktu sorting : %.2f ms\n", timeTaken);
                break;

            case 3:
                start = clock();
                heapSort(data, getTotalWords());
                end = clock();

                timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

                saveToFile("output_heapsort.txt", data, getTotalWords(), timeTaken);
                printf("Hasil berhasil disimpan.\n");
                printf("Waktu sorting : %.2f ms\n", timeTaken);
                break;

            case 4:
                printf("Masukkan nilai k : ");
                // Validasi input nilai K jika user memasukkan huruf
                if (scanf("%d", &k) != 1) {
                    printf("\nError: Nilai K harus berupa angka!\n");
                    clearBuffer();
                    break;
                }

                start = clock();
                quickSort(data, 0, getTotalWords() - 1);
                end = clock();

                timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

                printTopK(data, k);
                printf("\nWaktu sorting : %.2f ms\n", timeTaken);
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