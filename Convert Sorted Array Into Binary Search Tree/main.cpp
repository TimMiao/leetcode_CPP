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

class sortedArrayToBST {
public:
    TreeNode* BSTGenerator(vector<int>& nums, int left_side, int right_side) {
        if (left_side > right_side)
            return nullptr;
        int mid_point = left_side + (right_side - left_side) / 2;
        TreeNode* tree = new TreeNode(nums[mid_point]);
        tree->left = BSTGenerator(nums, left_side, mid_point - 1);
        tree->right = BSTGenerator(nums, mid_point + 1, right_side);

        return tree;
    }

    TreeNode* convertSortedArrayToBST(vector<int>& nums) {
        return BSTGenerator(nums, 0, nums.size() - 1);
    }
};

void deleteTree(TreeNode* tree) {
    if (tree == nullptr)
        return;
    deleteTree(tree->left);
    deleteTree(tree->right);
    delete tree;
}

void print(TreeNode* root) {
    if (root == nullptr)
        return;
    print(root->left);
    cout << root->val << ",";
    print(root->right);
}

int main() {
    vector<int> vec = {-10,-3,0,5,9};
    sortedArrayToBST BST;
    TreeNode* tree = BST.convertSortedArrayToBST(vec);

    print(tree);

    deleteTree(tree);

    return 0;
}