#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = static_cast<int>(s.size());
        vector<int> dp(n, 0);
        int best = 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] != ')') {
                continue;
            }

            if (s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else {
                int prev = dp[i - 1];
                int j = i - prev - 1;
                if (j >= 0 && s[j] == '(') {
                    dp[i] = prev + 2 + (j >= 1 ? dp[j - 1] : 0);
                }
            }

            if (dp[i] > best) {
                best = dp[i];
            }
        }

        return best;
    }
};
