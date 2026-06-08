#include <stdio.h>
#include "sorting.h"

/* ==================================================
   Utility Function
   ================================================== */

static void swap(WordFreq *a, WordFreq *b)
{
    WordFreq temp = *a;
    *a = *b;
    *b = temp;
}

/* ==================================================
   INSERTION SORT (Descending)
   ================================================== */

void insertionSort(WordFreq arr[], int n)
{
    int i, j;
    WordFreq key;

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j].freq < key.freq)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

/* ==================================================
   QUICK SORT (Descending)
   ================================================== */

static int partition(WordFreq arr[], int low, int high)
{
    long long pivot = arr[high].freq;

    int i = low - 1;

    int j;

    for(j = low; j < high; j++)
    {
        if(arr[j].freq > pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(WordFreq arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* ==================================================
   HEAP SORT (Descending)
   ================================================== */

static void heapify(WordFreq arr[], int n, int i)
{
    int largest = i;

    int left  = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left].freq > arr[largest].freq)
        largest = left;

    if(right < n && arr[right].freq > arr[largest].freq)
        largest = right;

    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(WordFreq arr[], int n)
{
    int i;

    /* Build Max Heap */
    for(i = n/2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    /* Heap Sort */
    for(i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }

    /* Reverse agar descending */
    int start = 0;
    int end   = n - 1;

    while(start < end)
    {
        swap(&arr[start], &arr[end]);

        start++;
        end--;
    }
}
