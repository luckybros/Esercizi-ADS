#include "Solution.h"
#include <iostream>
#include <cmath>
using namespace std;

Solution::Solution() {
    numInversions = 0;
}

int Solution::getNumInversions() {
    return numInversions;
}

void Solution::MergeSort(int array[], int p, int r) {
    if (r > p) {
        int q = floor((p + r) / 2);
        MergeSort(array, p, q);
        MergeSort(array, q + 1, r);
        Merge(array, p, q, r);
    }
}

void Solution::InsertionSort(int array[], int n) {
    int i, j, min, temp;
    for(i = 1; i < n; i++) {
        min = array[i];
        j = i -1;
        while(j >= 0 && array[j] > min) {
            temp = array[j+1];
            array[j+1] = array[j];
            array[j] = temp;
            j--;
            numInversions++;
        }
    }
}

void Solution::Merge(int array[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int lowHalf[n1];
    int highHalf[n2];

    int k = p;
    int i, j;

    for (i = 0; i < n1; i++) {
        lowHalf[i] = array[k];
        k++;
    }

    for (j = 0; j < n2; j++) {
        highHalf[j] = array[k];
        k++;
    }

    k = p;
    i = j = 0;

    while (i < n1 && j < n2) {
        if (lowHalf[i] <= highHalf[j]) {
            array[k] = lowHalf[i];
            i++;
        } else {
            array[k] = highHalf[j];
            j++;
            // elemento da spostare in pos n1 + j, 
            // deve arrivare in posizione i + j
            // n di passi n1 + j - (i + j)
            numInversions += n1 - i;
        }
        k++;
    }

    while (i < n1) {
        array[k] = lowHalf[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = highHalf[j];
        j++;
        k++;
    }
}

void Solution::QuickSort(int array[], int p, int r) {
    if(p < r) {
        int q = Partition(array, p, r);
        QuickSort(array, p, q-1);
        QuickSort(array, q+1, r);
    }

}

int Solution::Partition(int array[], int p, int r) {
    int pivot = array[r];
    int i = p-1;
    int j = p;

    while(j < r) {
        if(array[j] <= pivot) {
            i++;
            Swap(&array[i], &array[j]);
        }
        j++;
    }

    Swap(&array[i+1], &array[r]);
    return i+1;
}

void Solution::Swap(int *a, int *b)
{   
    if(a == b)  
        return;
        
    int temp = *a;
    *a = *b;
    *b = temp;
    this->numInversions++;
}


