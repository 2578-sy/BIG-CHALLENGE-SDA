#ifndef SORTING_H
#define SORTING_H

#include "data.h"

/* Insertion Sort (descending) */
void insertionSort(WordData arr[], int n);

/* Quick Sort (descending) */
void quickSort(WordData arr[], int low, int high);

/* Heap Sort (descending) */
void heapSort(WordData arr[], int n);

#endif
