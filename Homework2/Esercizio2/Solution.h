#ifndef SOLUTION_H
#define SOLUTION_H
#include <iostream>
using namespace std;

class Solution {
    private:
    int dimension, numSolutions;
    int** chessboard;
    bool isFinished;

    public:
    void setN(int);
    int FindNQueens();
    void Backtracking(int);
    bool IsSolution(int);
    bool MakeMove(int, int);
    void UnmakeMove(int, int);
    void PrintChessboard();
};


#endif