#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Write position k; first element is always kept when n >= 1
        int n = static_cast<int>(nums.size());
        if (n == 0) {
            return 0;
        }
        int k = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
