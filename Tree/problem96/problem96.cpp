#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // dp[i] = number of BST shapes with i nodes (values 1..i).
        // Root j has left subtree size j-1 and right subtree size i-j.
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return static_cast<int>(dp[n]);
    }
};
