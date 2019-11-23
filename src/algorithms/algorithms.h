#ifndef ALGORITHMS_LAB1_ALGORITHMS_H
#define ALGORITHMS_LAB1_ALGORITHMS_H


#include <cstdlib>
#include <cstring>

#include "../heap/heap.h"

class Algorithms {
    static void swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    static int partition(int arr[], int from, int to) {
        int pivot = arr[to];

        int i = from - 1;  // Index of smaller element

        for (int j = from; j <= to - 1; j++)
        {
            // If current element is smaller than the pivot
            if (arr[j] < pivot)
            {
                i++;    // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[to]);
        return i + 1;
    }

    static bool isSorted(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                return false;
            }
        }
        return true;
    }

    static void shuffle(int a[], int n) {
        for (int i = 0; i < n; ++i) {
            swap(&a[i], &a[rand() % n]);
        }
    }

    static void siftDown(int arr[], int root, int bottom)
    {
        int maxChildIndex;
        bool isFormed = false;

        while (root * 2 <= bottom && !isFormed) {
            if (root * 2 == bottom) {
                maxChildIndex = root * 2;
            } else if (arr[root * 2] > arr[root * 2 + 1]) {
                maxChildIndex = root * 2;
            } else {
                maxChildIndex = root * 2 + 1;
            }

            if (arr[root] < arr[maxChildIndex]) {
                int temp = arr[root]; // swap them
                arr[root] = arr[maxChildIndex];
                arr[maxChildIndex] = temp;
                root = maxChildIndex;
            } else {
                isFormed = true;
            }
        }
    }
public:
    static bool binarySearch(int arr[], int from, int to, int val) {
        if (from > to || (from == 0 && to == 0) || (from < 0 || to < 0)) {
            return false;
        }

        int mid = from + (to - from) / 2;
        if (arr[mid] == val) {
            return true;
        }

        return val < arr[mid] ? binarySearch(arr, from, mid - 1, val) : binarySearch(arr, mid + 1, to, val);
    }

    static void quickSort(int arr[], int from, int to) {
        if (from > to || (from == 0 && to == 0) || (from < 0 || to < 0)) {
            return;
        }

        int part_index = partition(arr, from, to);

        quickSort(arr, from, part_index - 1);
        quickSort(arr, part_index + 1, to);
    }

    static void bubbleSort(int arr[], int length)
    {
        for (int i = 0; i < length -1; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(&arr[j], &arr[j+1]);
                }
            }
        }
    }

    static void bogoSort(int arr[], int length) {
        while (!isSorted(arr, length)) {
            shuffle(arr, length);
        }
    }

    static void countSort(char arr[], int length) {
        char output[length];
        const int BITS_IN_CHAR = 256;
        int count[BITS_IN_CHAR]{ 0 };

        for (int i = 0; i < length; i++) {
            count[arr[i]]++;
        }

        int index = 0;
        for (int c = 0; c < BITS_IN_CHAR; c++) {
            for (int i = 0; i < count[c]; i++) {
                arr[index] = c;
                index++;
            }
        }
    }

    static void heapSort(int arr[], int length) {
        if (length == 0) {
            return;
        }

        for (int i = length / 2 - 1; i >= 0; i--) {
            siftDown(arr, i, length - 1);
        }

        // Sifting through the heap other elements
        for (int i = length - 1; i >= 1; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            siftDown(arr, 0, i - 1);
        }
    }
};


#endif //ALGORITHMS_LAB1_ALGORITHMS_H
