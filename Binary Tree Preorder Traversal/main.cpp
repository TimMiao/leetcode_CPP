#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class PreorderTraversal {
public:
    vector<int> BSTPreorderTraversal(TreeNode* root) {
        vector<int> node_vec;
        preorder(root, node_vec);
        return node_vec;
    }

private:
    void preorder(TreeNode* root, vector<int>& node_vec){
        if (root) {
            node_vec.push_back(root->val);
            preorder(root->left, node_vec);
            preorder(root->right, node_vec);
        }
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
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);

    PreorderTraversal BSTPT;
    vector<int> node_vec = BSTPT.BSTPreorderTraversal(root);

    for (int i = 0; i < node_vec.size(); ++i) {
        if (i < node_vec.size() - 1)
            cout << node_vec[i] << ',';
        else
            cout << node_vec[i];
    }

    deleteTree(root);
    return 0;
}