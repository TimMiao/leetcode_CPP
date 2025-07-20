#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class InorderTraversal {
public:
    vector<int> inorderTrav(TreeNode* root) {
        vector<int> final_vec;
        auto curr_node = root;
        stack<TreeNode*> temp_stack;

        while(curr_node != nullptr || !temp_stack.empty()) {
            while(curr_node != nullptr) {
                temp_stack.push(curr_node);
                curr_node = curr_node->left;
            }
            curr_node = temp_stack.top();
            temp_stack.pop();
            final_vec.push_back(curr_node->val);
            curr_node = curr_node->right;
        }
        return final_vec;
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
    root->left = nullptr;
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> final_vec;
    InorderTraversal tree;
    final_vec = tree.inorderTrav(root);

    for (auto ele : final_vec){
        cout << ele << endl;
    }

    deleteTree(root);

    return 0;
}