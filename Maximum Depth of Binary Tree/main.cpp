#include <iostream>
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

class maximumDepthOfBinaryTree {
public:
    int maxDepth (TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        auto left_depth = maxDepth(root->left);
        auto right_depth = maxDepth(root->right);
        return max(left_depth, right_depth) + 1;
    }
};

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    maximumDepthOfBinaryTree max_depth;

    int depth = max_depth.maxDepth(root);
    cout << depth << endl;

    deleteTree(root);

    return 0;
}

