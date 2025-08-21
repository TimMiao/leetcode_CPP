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

class minDepthBinaryTree {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        int l_height = minDepth(root->left);
        int r_height = minDepth(root->right);

        if (!root->left) return 1 + r_height;
        if (!root->right) return 1 + l_height;

        return 1 + min(l_height, r_height);
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
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    minDepthBinaryTree minDBT;
    int depth = minDBT.minDepth(root);

    cout << depth << endl;

    deleteTree(root);

    TreeNode* node = new TreeNode(2);
    node->right = new TreeNode(3);
    node->right->right = new TreeNode(4);
    node->right->right->right = new TreeNode(5);
    node->right->right->right->right = new TreeNode(6);

    depth = minDBT.minDepth(node);

    cout << depth << endl;

    deleteTree(node);
}