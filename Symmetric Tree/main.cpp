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

class symmetricTree {
public:
    bool reflection(TreeNode* l, TreeNode* r) {
        if (!l && !r)
            return true;
        if (!l || !r)
            return false;
        return (l->val == r->val)
            && reflection(l->left, r->right)
            && reflection(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return reflection(root->left, root->right);
    }
};

void deleteTree(TreeNode* root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    symmetricTree symTree;
    cout << symTree.isSymmetric(root) << endl;

    deleteTree(root);

    return 0;
}