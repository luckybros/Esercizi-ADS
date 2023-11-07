#include <iostream>
#include <utility>
using namespace std;

class Solution {

    public:
    int max;
    bool **boolean;
    int dimension;

    Solution(const int dimension) {
        max = 0;
        this->dimension = dimension;
        boolean = new bool*[dimension]; 

        for (int i = 0; i < dimension; i++) {
            boolean[i] = new bool[dimension]; 
            for (int j = 0; j < dimension; j++) {
                boolean[i][j] = false; 
            }
        }     
    }

    int findLongestTrack(int** track) {
        Backtracking(track, 0, 0, 0, this->dimension);
        return max;
    }

    void Backtracking(int** track, int row, int colon, int count, int dimension) {
        if(count > max)
            max = count;

        for(int i = row; i < dimension; i++)
            for(int j = colon; j < dimension; j++) 
                if(!boolean[i][j]) {
                    boolean[i][j] = true;
                    if(j > 0 && Check(track, make_pair(i, j), make_pair(i, j-1)))
                        Backtracking(track, i, j-1, count+1, dimension);
                    if(j < dimension-1  && Check(track, make_pair(i, j), make_pair(i, j+1)))
                        Backtracking(track, i, j+1, count+1, dimension);
                    if(i > 0 && Check(track, make_pair(i, j), make_pair(i-1, j)))
                        Backtracking(track, i-1, j, count+1, dimension);
                    if(i < dimension-1  && Check(track, make_pair(i, j), make_pair(i+1, j)))
                        Backtracking(track, i+1, j, count+1, dimension);
                }
    }

    bool Check(int** track, pair<int,int> oldPosition, pair<int,int> newPosition) {
        if(track[oldPosition.first][oldPosition.second] > track[newPosition.first][newPosition.second])
            return true;
        else
            return false;
    }
};

int main() {
    const int dimension = 5;
    // Definizione dell'array multidimensionale
    int track[dimension][dimension] = {
        {1, 2, 3, 4, 5},
        {16, 17, 18, 19, 6},
        {15, 24, 25, 20, 7},
        {14, 23, 22, 21, 8},
        {13, 12, 11, 10, 9}
    };

    // Allocazione di un array di puntatori
    int** trackPtr = new int*[dimension];
    for (int i = 0; i < dimension; ++i) {
        trackPtr[i] = track[i]; // Ogni puntatore punta alla relativa riga dell'array multidimensionale
    }

    Solution soluzione(dimension);

    cout << soluzione.findLongestTrack(trackPtr);
    delete[] trackPtr;
}