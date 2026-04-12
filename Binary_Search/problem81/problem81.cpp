#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Rotated sorted array with duplicates: compare mid to ends to see which side is ordered.
        // When nums[lo] == nums[mid], we cannot tell which half is sorted, so shrink lo (worst case O(n)).
        int lo = 0;
        int hi = static_cast<int>(nums.size()) - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[lo] < nums[mid]) {
                if (nums[lo] <= target && target < nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else if (nums[lo] > nums[mid]) {
                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            } else {
                ++lo;
            }
        }
        return false;
    }
};
