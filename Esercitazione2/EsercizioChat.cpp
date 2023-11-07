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
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                Backtracking(track, i, j, 1); // Inizia il backtracking da ogni punto
            }
        }
        return max;
    }

    void Backtracking(int** track, int row, int colon, int count) {
        if (count > max)
            max = count;

        int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        for (int k = 0; k < 4; k++) {
            int newRow = row + directions[k][0];
            int newCol = colon + directions[k][1];

            if (newRow >= 0 && newRow < dimension && newCol >= 0 && newCol < dimension &&
                !boolean[newRow][newCol] && Check(track, make_pair(row, colon), make_pair(newRow, newCol))) {
                boolean[newRow][newCol] = true;
                Backtracking(track, newRow, newCol, count + 1);
                boolean[newRow][newCol] = false;
            }
        }
    }

    bool Check(int** track, pair<int, int> oldPosition, pair<int, int> newPosition) {
        return (track[oldPosition.first][oldPosition.second] > track[newPosition.first][newPosition.second]);
    }
};

int main() {
    const int dimension = 5;
    int track[dimension][dimension] = {
        {1, 2, 3, 4, 5},
        {16, 17, 18, 19, 6},
        {15, 24, 25, 20, 7},
        {14, 23, 22, 21, 8},
        {13, 12, 11, 10, 9}
    };

    int** trackPtr = new int*[dimension];
    for (int i = 0; i < dimension; ++i) {
        trackPtr[i] = track[i];
    }

    Solution solution(dimension);

    cout << solution.findLongestTrack(trackPtr) << endl;

    delete[] trackPtr;
}
