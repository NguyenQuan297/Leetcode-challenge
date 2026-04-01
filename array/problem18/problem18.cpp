#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Avoid 32-bit overflow when summing four values near 1e9
        long long T = target;
        sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        vector<vector<int>> res;
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int lo = j + 1, hi = n - 1;
                while (lo < hi) {
                    long long s = static_cast<long long>(nums[i]) + nums[j] + nums[lo] + nums[hi];
                    if (s < T) {
                        lo++;
                    } else if (s > T) {
                        hi--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[lo], nums[hi]});
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
        }
        return res;
    }
};
