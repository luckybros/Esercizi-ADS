//  La compelssità è data dal ciclo eseguito, di conseguenza è O(n^2)


#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int calcolaDifferenzaMinima(int valoriMonete[], int dimensione) {
        int M = dimensione;

        if (M == 1)
            return valoriMonete[0];
        if (M == 2) 
            return abs(valoriMonete[1] - valoriMonete[0]);

        int** memo = new int*[M];
        for (int i = 0; i < M; i++) 
            memo[i] = new int[M];

        int sommaTotale = 0;
        for (int i = 0; i < M; i++) 
            sommaTotale += valoriMonete[i];

        int sommaAttesa = sommaTotale / 2;
        int maxSommaParziale = 0;

        for (int i = 0; i < M; i++) 
            memo[i][i] = valoriMonete[i];

        for (int i = 0; i < M; i++) 
            for (int j = i + 1; j < M; j++) {
                memo[i][j] = memo[i][j - 1] + valoriMonete[j];
                if (memo[i][j] > maxSommaParziale && memo[i][j] <= sommaAttesa) 
                    maxSommaParziale = memo[i][j];
            }

        for (int i = 1; i < M; i++) 
            for (int j = 0; j < i; j++) {
                memo[i][j] = memo[i][(M - 1 + j) % M] + valoriMonete[j];
                if (memo[i][j] > maxSommaParziale && memo[i][j] <= sommaAttesa) 
                    maxSommaParziale = memo[i][j];
            }
        

        for (int i = 0; i < M; i++) 
            delete[] memo[i];
        delete[] memo;

        return abs(sommaTotale - 2 * maxSommaParziale);
    }
};

int main() {
    Solution solution;

    int casiDiTest;
    cout << "Inserisci il numero di casi di test: ";
    cin >> casiDiTest;

    for (int t = 0; t < casiDiTest; t++) {
        int M;
        cout << "Inserisci il numero di monete per il caso di test " << (t + 1) << ": ";
        cin >> M;

        int* valoriMonete = new int[M];
        cout << "Inserisci i valori delle monete separati da spazio: ";
        for (int i = 0; i < M; i++) {
            cin >> valoriMonete[i];
        }

        int differenzaMinima = solution.calcolaDifferenzaMinima(valoriMonete, M);

        cout << "Risultato per il caso di test " << (t + 1) << ": " << differenzaMinima << endl;

        delete[] valoriMonete;
    }

    return 0;
}
