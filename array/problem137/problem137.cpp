#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Bitmask DP: ones holds bits seen 1 mod 3, twos holds bits seen 2 mod 3
        int ones = 0;
        int twos = 0;
        for (int x : nums) {
            ones = (ones ^ x) & ~twos;
            twos = (twos ^ x) & ~ones;
        }
        return ones;
    }
};
