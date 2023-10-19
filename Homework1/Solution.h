#ifndef SOLUTION_H
#define SOLUTION_H

class Solution {
private:
    int numInversions;

public:
    Solution();
    int getNumInversions();
    void MergeSort(int[], int, int);
    void InsertionSort(int[], int);
    void QuickSort(int[], int, int);
    void Merge(int[], int, int, int);
    int Partition(int[], int, int);
    void Swap(int*, int*);
};

#endif
