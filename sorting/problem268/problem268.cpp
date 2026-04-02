#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int x = n;
        for (int i = 0; i < n; ++i) {
            x ^= i ^ nums[i];
        }
        return x;
    }
};
