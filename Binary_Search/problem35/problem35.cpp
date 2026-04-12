#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Lower bound: first index i such that nums[i] >= target.
        // If target exists, that index is where it sits; otherwise it is the insert position.
        int lo = 0;
        int hi = static_cast<int>(nums.size());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
