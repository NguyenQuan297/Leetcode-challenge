#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Fix first element index i; two-pointer search for the other two
        sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        vector<vector<int>> res;
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int s = nums[lo] + nums[hi];
                if (s < target) {
                    lo++;
                } else if (s > target) {
                    hi--;
                } else {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    lo++;
                    hi--;
                    while (lo < hi && nums[lo] == nums[lo - 1]) {
                        lo++;
                    }
                    while (lo < hi && nums[hi] == nums[hi + 1]) {
                        hi--;
                    }
                }
            }
        }
        return res;
    }
};
