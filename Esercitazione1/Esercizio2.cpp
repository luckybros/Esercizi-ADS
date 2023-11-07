#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    bool flag;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr), flag(false) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), flag(false) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right), flag(false) {}
};

class Solution {
    public:
    int getLastSpot(TreeNode* head, int numBalls, int depth) {
        int lastSpot;
        if(depth == 1)
            return head->val;
        for(int i = 0; i < numBalls; i++)
            lastSpot = Recursive(head, depth);
        return lastSpot;
    }

    int Recursive(TreeNode* head, int depth) {
        if(depth == 1)
            return head->val;
        int lastSpot;

        if(!head->flag) {
            lastSpot = Recursive(head->left, depth-1);
            head->flag = true;
        }
            
        else if(head->flag) {
            lastSpot = Recursive(head->right, depth-1);
            head->flag = false;
        }
        return lastSpot;
    }

    TreeNode* buildTree(int nodeVal, int height) {
        if (height <= 0) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(nodeVal);

        if (height > 1) {
            root->left = buildTree(2 * nodeVal, height - 1);
            root->right = buildTree(2 * nodeVal + 1, height - 1);
        }

        return root;
    }
};

int main() {
    Solution soluzione;
    int depth = 10;
    int nPalline = 1;
    TreeNode* head = soluzione.buildTree(1, depth);

    cout << soluzione.getLastSpot(head, nPalline, depth);
}