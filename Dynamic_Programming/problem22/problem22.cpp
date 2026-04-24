#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};

        for (int k = 1; k <= n; ++k) {
            vector<string> cur;
            for (int i = 0; i < k; ++i) {
                for (const string& left : dp[i]) {
                    for (const string& right : dp[k - 1 - i]) {
                        cur.push_back("(" + left + ")" + right);
                    }
                }
            }
            dp[k] = move(cur);
        }

        return dp[n];
    }
};
