#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class balancedBinaryTree {
public:
    int heightGetter(TreeNode* root) {
        if (!root) return 0;

        int l_height = heightGetter(root->left);
        if (l_height == -1) return -1;

        int r_height = heightGetter(root->right);
        if (r_height == -1) return -1;

        if (abs(l_height - r_height) > 1) return -1;

        return 1 + max(l_height, r_height);
    }

    bool ifBalanced(TreeNode* root) {
        return (heightGetter(root) != -1);
    }
};

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(20);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(15);

    balancedBinaryTree checkBalanced;
    cout << checkBalanced.ifBalanced(root) << endl;

    deleteTree(root);
}