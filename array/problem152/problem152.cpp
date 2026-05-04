#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int best   = nums[0];

        for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
            int x = nums[i];
            int prevMax = curMax;
            curMax = max({x, prevMax * x, curMin * x});
            curMin = min({x, prevMax * x, curMin * x});
            best   = max(best, curMax);
        }

        return best;
    }
};
