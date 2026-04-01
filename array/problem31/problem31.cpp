#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        // 1) Rightmost index i where nums[i] < nums[i+1] (pivot before non-increasing suffix)
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end()); // last permutation -> smallest
            return;
        }
        // 2) Swap nums[i] with the smallest larger element to its right
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
        // 3) Reverse suffix so it becomes the lexicographically smallest tail
        reverse(nums.begin() + i + 1, nums.end());
    }
};
