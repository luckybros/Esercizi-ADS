#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {

    private:
    vector<int> solution, trueSolution;
    int minPenality, dimension;
    
    public:
    Solution(int dimension) {
        this->dimension = dimension;
        minPenality = INT_MAX;
        solution.resize(dimension);
        trueSolution.resize(dimension);
        for(int i = 0; i < dimension; i++) {
            solution[i] = 0;
            trueSolution[i] = 0;
        }
            
    }

    void Backtracking(vector<int> jobsTime, vector<int> penalities, int index, int dimension, int currentPenality, int currentDay) {
        if(index == dimension) {
            if(currentPenality < minPenality) {
                minPenality = currentPenality;
                trueSolution = solution;
            }
            return;
        } 
        else 
            for(int i = 0; i < dimension; i++) 
                if(solution[i] == 0) {
                    int newCurrentDay = currentDay + jobsTime[i];
                    int newPenality = currentPenality + (newCurrentDay - jobsTime[i])*penalities[i];
                    solution[i] = index+1;
                    Backtracking(jobsTime, penalities, index+1, dimension, newPenality, newCurrentDay);
                    solution[i] = 0;
                }   
    }

    void printSolution() {
        for(int i = 0; i < dimension; i++)  
            cout << trueSolution[i] << endl;
    }
    
};

int main() {
    int dimension = 4;
    vector<int> jobsTime;
    vector<int> penalties;

    jobsTime.push_back(3);
    jobsTime.push_back(1);
    jobsTime.push_back(2);
    jobsTime.push_back(5);

    penalties.push_back(4);
    penalties.push_back(1000);
    penalties.push_back(2);
    penalties.push_back(5);

    Solution soluzione(dimension);

    soluzione.Backtracking(jobsTime, penalties, 0, dimension, 0, 0);

    soluzione.printSolution();

}