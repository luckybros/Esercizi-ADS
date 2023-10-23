#include <iostream>
#include "Solution.h" 
using namespace std;

int main() {
    Solution soluzione;

    int array[] = {9, 1, 0, 5, 4};

    soluzione.MergeSort(array, 0, sizeof(array)/sizeof(int) - 1);

    for(int i = 0; i < 5; i++)  
        cout << array[i] << " ";

    cout << endl;

    cout << soluzione.getNumInversions();

    return 0;
}