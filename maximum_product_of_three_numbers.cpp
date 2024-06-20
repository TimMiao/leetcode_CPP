#include <vector>
using std::vector;
#include <algorithm>
using std::max;

int maximumProduct(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int product = 0;
    int i = nums.size() - 1;
    return max(nums[i] * nums[i - 1] * nums[i - 2], nums[0] * nums[1] * nums[i]);
}