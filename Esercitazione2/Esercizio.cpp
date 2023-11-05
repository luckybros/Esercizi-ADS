#include <iostream>
using namespace std;

class Solution {
    private:
    int righe,colonne,nPassi;
    bool isFinished;

    public:
    Solution() {righe = colonne = nPassi = 0; isFinished = false; }

    void Backtracking(int solution[N][N], int path[N][N]) {
        if(IsSolution()) {
            ProcessSolution(solution);
            return;
        }
            
        else {
            MakeMove(solution, path);
            Backtracking(solution, path);
            if(isFinished)
                return;
            UnmakeMove(solution, path);
        }
    };

    bool IsSolution() {
        if(nPassi == 2*(N-1)) {
            isFinished = true;
            return true;
        }
        return false;
    }

    void MakeMove(int solution[N][N], int path[N][N]) {
        if(path[righe][colonne+1] == 1) {
            colonne++;
            nPassi++;
            solution[righe][colonne] = path[righe][colonne];
        }
        else if(path[righe+1][colonne] == 1) {
            righe++;
            nPassi++;
            solution[righe][colonne] = path[righe][colonne];
        }
    }

    void UnmakeMove(int solution[N][N], int path[N][N]) {
        if(path[righe][colonne-1] == 1) {
            solution[righe][colonne] = 0;
            colonne--;
            nPassi--;
        }
        else if(path[righe-1][colonne] == 1) {
            solution[righe][colonne] = 0;
            righe--;
            nPassi--;
        }
    }

    void ProcessSolution(int solution[N][N]) {
        for (int i = 0; i < N; i++) { 
            for (int j = 0; j < N; j++) { 
                cout << solution[i][j] << " "; 
            } 
            cout << endl; 
        } 
    }
};

int main() {
    Solution soluzione;

    int path[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0 ,0},
        {1, 1, 1, 1}
    };

    int solution[N][N] = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0 ,0},
        {0, 0, 0, 0}
    };

    soluzione.Backtracking(solution, path);
}