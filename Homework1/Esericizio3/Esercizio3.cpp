#include "Solution.h" 
using namespace std;

int main() {
    Solution solution;

    Node* root = new Node('G', 4);
    
    Node* A = new Node('B', 7);
    Node* B = new Node('H', 5);
    solution.Insert(root, A);
    solution.Insert(root, B);

    Node* C = new Node('A', 10);
    Node* D = new Node('E', 23);
    //A->setLeftChild(C);
    //A->setRightChild(D);
    solution.Insert(root, C);
    solution.Insert(root, D);

    Node* E = new Node('K', 65);
    //B->setRightChild(E);
    solution.Insert(root, E);

    Node* F = new Node('I', 73);
    //E->setLeftChild(F);
    solution.Insert(root, F);

    //solution.PrintTree(root);

    Node* G = new Node('C', 25);
    //D->setLeftChild(G);
    solution.Insert(root, G);

    Node* H = new Node('D', 9);
    solution.Insert(root, H);

    Node* I = new Node('F', 2);
    solution.Insert(root, I);

    solution.PrintTree(root);
}