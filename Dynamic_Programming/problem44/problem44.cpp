#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = static_cast<int>(s.size());
        int n = static_cast<int>(p.size());
        vector<char> dp(n + 1, 0);
        dp[0] = 1;

        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[j] = dp[j - 1];
            }
        }

        for (int i = 1; i <= m; ++i) {
            char prevDiag = dp[0];
            dp[0] = 0;
            for (int j = 1; j <= n; ++j) {
                char temp = dp[j];
                if (p[j - 1] == '*') {
                    dp[j] = (dp[j] || dp[j - 1]);
                } else {
                    dp[j] = (prevDiag && (p[j - 1] == '?' || p[j - 1] == s[i - 1]));
                }
                prevDiag = temp;
            }
        }

        return dp[n];
    }
};
