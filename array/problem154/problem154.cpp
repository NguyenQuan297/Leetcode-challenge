#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // With duplicates, worst-case can degrade to O(n)
        int lo = 0, hi = static_cast<int>(nums.size()) - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[hi]) {
                hi = mid;
            } else if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else {
                // nums[mid] == nums[hi] -> shrink right boundary
                --hi;
            }
        }
        return nums[lo];
    }
};
