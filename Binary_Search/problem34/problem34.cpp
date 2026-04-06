#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        if (n == 0) {
            return {-1, -1};
        }

        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (nums[lo] != target) {
            return {-1, -1};
        }
        int first = lo;

        lo = 0;
        hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        return {first, lo};
    }
};
