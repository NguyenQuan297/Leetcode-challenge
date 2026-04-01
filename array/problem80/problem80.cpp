#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int x : nums) {
            // Keep x if we have fewer than 2 kept elements of this value,
            // or if x differs from the element kept two positions ago.
            if (k < 2 || x != nums[k - 2]) {
                nums[k] = x;
                ++k;
            }
        }
        return k;
    }
};
