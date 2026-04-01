#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // Binary search using right boundary comparison
        int lo = 0, hi = static_cast<int>(nums.size()) - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return nums[lo];
    }
};
