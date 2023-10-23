#include "Solution.h" 
using namespace std;

int main() {
    Solution solution;

    Node* root = new Node('G', 4);
    Node* A = new Node('B', 7);
    Node* B = new Node('H', 5);
    root->setLeftChild(A);
    root->setRightChild(B);

    Node* C = new Node('A', 10);
    Node* D = new Node('E', 23);
    A->setLeftChild(C);
    A->setRightChild(D);

    Node* E = new Node('K', 65);
    B->setRightChild(E);

    Node* F = new Node('I', 73);
    E->setLeftChild(F);

    //solution.PrintTree(root);

    Node* G = new Node('C', 25);
    D->setLeftChild(G);

    Node* H = new Node('D', 9);
    solution.Insert(root, H);

    solution.PrintTree(root);
}