#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        int last = static_cast<int>(nums.size()) - 1;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (i > farthest) {
                return false;
            }
            farthest = max(farthest, i + nums[i]);
            if (farthest >= last) {
                return true;
            }
        }

        return true;
    }
};
