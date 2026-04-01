#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Compact non-val elements to the front
        int k = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
