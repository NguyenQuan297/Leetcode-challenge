#include <algorithm>
#include <climits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = static_cast<int>(t.size());
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (char ch : s) {
            for (int j = n; j >= 1; --j) {
                if (ch == t[j - 1]) {
                    dp[j] = min(dp[j] + dp[j - 1], (long long)INT_MAX);
                }
            }
        }

        return static_cast<int>(dp[n]);
    }
};
