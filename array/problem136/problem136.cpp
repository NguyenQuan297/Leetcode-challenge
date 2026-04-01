#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR cancels pairs: a ^ a = 0
        int x = 0;
        for (int v : nums) {
            x ^= v;
        }
        return x;
    }
};
