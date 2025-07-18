#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    std::vector<int> final_vec;
    for (size_t i = 0; i < nums1.size(); ++i) {
        auto itr = std::find(nums2.begin(), nums2.end(), nums1[i]);
        if (itr != nums2.end()) {
            int idx = itr - nums2.begin();
            if (nums2[idx + 1] > nums2[idx]) {
                final_vec.push_back(nums2[idx + 1]);
            }
            else {
                final_vec.push_back(-1);
            }
        }
    }
    return final_vec;
}

int main() {
    vector<int> nums1 {2,4};
    vector<int> nums2 {1,2,3,4};
    vector<int> final_vec = nextGreaterElement(nums1, nums2);
    for (size_t i = 0; i < final_vec.size(); ++i) {
        cout << final_vec[i] << endl;
    }
}