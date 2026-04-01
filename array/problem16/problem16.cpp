#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; ++i) {
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int s = nums[i] + nums[lo] + nums[hi];
                if (s == target) {
                    return target;
                }
                if (abs(s - target) < abs(closest - target)) {
                    closest = s;
                }
                if (s < target) {
                    lo++;
                } else {
                    hi--;
                }
            }
        }
        return closest;
    }
};
