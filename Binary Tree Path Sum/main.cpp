#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTreePathSum {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;

        if (!root->left && !root->right) return targetSum == root->val;

        bool leftSum = hasPathSum(root->left, targetSum - root->val);
        bool rightSum = hasPathSum(root->right, targetSum - root->val);

        return leftSum || rightSum;
    }
};

void deleteTree(TreeNode* root) {
    if (!root) return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(17);
    root->left->left->left = new TreeNode(12);
    root->right = new TreeNode(7);
    root->right->right = new TreeNode(19);
    root->right->right->right = new TreeNode(11);

    BinaryTreePathSum BSTPathSum;

    bool finder = BSTPathSum.hasPathSum(root, 23);

    cout << finder << endl;

    deleteTree(root);

    return 0;
}