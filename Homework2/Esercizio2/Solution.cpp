#include "Solution.h"

Solution::Solution(int dimension) {
    this->dimension = dimension;
    numSolutions = 0;
    chessboard = new int*[dimension];
    isFinished = false;
    for (int i = 0; i < dimension; ++i) {
        chessboard[i] = new int[dimension];
    }
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
           chessboard[i][j] = 0; 
        }
    }
}

int Solution::FindNQueens() {
    Backtracking(0);
    return numSolutions;
}

void Solution::Backtracking(int colons) {
    if(IsSolution(colons)) 
        return;
    else 
        for(int i = 0; i < dimension; i++)
            if(MakeMove(i, colons)) {
                Backtracking(colons+1);
                UnmakeMove(i, colons);
            }
};

bool Solution::IsSolution(int colons) {
    if(colons == dimension) {
        numSolutions++;
        return true;
    }
    return false;
}

bool Solution::MakeMove(int rows, int colons) {
    int i, j;

    for(j = 0; j < colons; j++)
        if(chessboard[rows][j] != 0) 
            return false;

    for(i = rows, j = colons; i >= 0 && j >= 0; i--, j-- ) 
        if(chessboard[i][j] != 0)
            return false;

    for(i = rows, j = colons; i < dimension && j >= 0; i++, j-- ) 
        if(chessboard[i][j] != 0)
            return false;

    chessboard[rows][colons] = 1;
    
    return true;
}

void Solution::UnmakeMove(int rows, int colons) {
    chessboard[rows][colons] = 0;
}

void Solution::PrintChessboard() {
    for (int i = 0; i < dimension; i++) { 
        for (int j = 0; j < dimension; j++) { 
            cout << chessboard[i][j] << " "; 
        } 
        cout << endl; 
    } 
}



