#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        int mid = (n + 1) / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());
        reverse(left.begin(), left.end());
        reverse(right.begin(), right.end());
        for (int i = 0; i < static_cast<int>(left.size()); ++i) {
            nums[2 * i] = left[i];
        }
        for (int i = 0; i < static_cast<int>(right.size()); ++i) {
            nums[2 * i + 1] = right[i];
        }
    }
};
