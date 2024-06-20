#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::find;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> final_vec;
    for (size_t i = 0; i < nums1.size(); ++i) {
        if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end()) {
            if (nums2.size() == 1) {
                final_vec.push_back(nums1[i]);
                break;
            }
            final_vec.push_back(nums1[i]);
        }
    }
    return final_vec;
}

int main() {
    vector<int> nums1 {1,2,2,1};
    vector<int> nums2 {2,2};
    vector<int> final_vec = intersect(nums1, nums2);
    for (size_t i = 0; i < final_vec.size(); ++i) {
        cout << final_vec[i] << endl;
    }
}