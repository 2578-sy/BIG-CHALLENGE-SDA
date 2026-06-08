#ifndef SORTING_H
#define SORTING_H

#include "data.h"

/* Insertion Sort */
void insertionSort(WordFreq arr[], int n);

/* Quick Sort */
void quickSort(WordFreq arr[], int low, int high);

/* Heap Sort */
void heapSort(WordFreq arr[], int n);

#endif
