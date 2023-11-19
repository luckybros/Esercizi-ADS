#include "Solution.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt"); 
    int n;

    if (!inputFile.is_open()) {
        std::cerr << "Impossibile aprire il file di input." << std::endl;
        return 1; 
    }

    Solution solution;

    while (inputFile >> n) {
        if (n == -1) 
            break;
        
        solution.setN(n); 
        int result = solution.FindNQueens();
        std::cout << "N = " << n << ": " << result << std::endl;
    }
    inputFile.close(); 
    return 0; 
}
