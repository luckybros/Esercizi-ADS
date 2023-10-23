#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
using namespace std;
#define COUNT 10

class Node {
    private:
    char key;
    int priority;
    Node* right;
    Node* left;

    public:
    Node();
    Node(char, int);
    Node(Node&);
    char getKey() {return key;}
    int getPriority() {return priority;}
    Node* getRightChild() {return right;}
    Node* getLeftChild() {return left;}
    void setKey(char key) {this->key = key;}
    void setPriority(int priority) {this->priority = priority;}
    void setRightChild(Node* right) {this->right = right;}
    void setLeftChild(Node* left) {this->left = left;}
};

class Solution {
    public:
    void MinHeapify(Node*);  
    void BuildMinHeap(Node*);
    void Swap(Node*, Node*);
    Node* Insert(Node*, Node*);
    Node* RotateRight(Node*);
    Node* RotateLeft(Node*);
    void PrintTree(Node*);
    void PrintTreeUtil(Node*, int);
};

#endif