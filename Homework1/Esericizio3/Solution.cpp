#include "Solution.h"

Node::Node() {
    key = 0;
    priority = 0;
    right = NULL;
    left = NULL;
}

Node::Node(char key, int priority) {
    this->key = key;
    this->priority = priority;
    left = NULL;
    right = NULL;
}

void Solution::MinHeapify(Node* root) {
    if(root->getRightChild() == NULL && root->getLeftChild() == NULL) 
        return;

    Node* rightChild = root->getRightChild();
    Node* leftChild = root->getLeftChild();
    Node* smallestNode = NULL;

    int leftPriority;
    int rightPriority;
    
    if(leftChild != NULL)
        leftPriority = leftChild->getPriority();
    if(rightChild != NULL) 
        rightPriority = rightChild->getPriority();
    int minPriority = root->getPriority();

    if(rightChild != NULL && rightPriority < minPriority) {
        minPriority = rightPriority;
        smallestNode = rightChild;
    }

    if(leftChild != NULL && leftPriority < minPriority) {
        minPriority = leftPriority;
        smallestNode = leftChild;
    }
        
    if(minPriority != root->getPriority()) {
        Swap(root, smallestNode);
        MinHeapify(smallestNode);
    }
}

void Solution::BuildMinHeap(Node* root) {
    if(root == NULL) 
        return;

    BuildMinHeap(root->getLeftChild());
    MinHeapify(root);
    BuildMinHeap(root->getRightChild());
}

void Solution::Swap(Node* first, Node* second) {
    char tempKey = first->getKey();
    int tempPriority = first->getPriority();

    first->setKey(second->getKey());
    first->setPriority(second->getPriority());

    second->setKey(tempKey);
    second->setPriority(tempPriority);
}

Node* Solution::Insert(Node* root, Node* added) {
    if(root == NULL) 
        return added;

    if(added->getKey() < root->getKey()) {
        root->setLeftChild(Insert(root->getLeftChild(), added));
        if(root->getLeftChild()->getPriority() < root->getPriority())
            root = RotateRight(root); 
    }
        
    if(added->getKey() > root->getKey()) {
        root->setRightChild(Insert(root->getRightChild(), added));
        if(root->getRightChild()->getPriority() < root->getPriority())
            root = RotateLeft(root);
    }

    return root;
}

Node* Solution::RotateRight(Node* y){
	Node* x = y->getLeftChild();
    Node* T2 = x->getRightChild();

    x->setRightChild(y);
    y->setLeftChild(T2);

    return x;
}

Node* Solution::RotateLeft(Node* x){
    Node* y = x->getRightChild();
    Node* T2 = y->getLeftChild();

    y->setLeftChild(x);
    x->setRightChild(T2);

    return y;
}

void Solution::PrintTree(Node* root) {
    PrintTreeUtil(root, 0);
}

void Solution::PrintTreeUtil(Node* root, int space) {
    if (root == NULL)
        return;
 
    space += COUNT;
 
    PrintTreeUtil(root->getRightChild(), space);

    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->getKey() << "\n";
 
    PrintTreeUtil(root->getLeftChild(), space);
}



