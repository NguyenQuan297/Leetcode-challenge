#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int prev2 = 1;
        int prev1 = (s[0] != '0') ? 1 : 0;

        for (int i = 2; i <= static_cast<int>(s.size()); ++i) {
            int cur = 0;
            if (s[i - 1] != '0') {
                cur += prev1;
            }
            int two = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (two >= 10 && two <= 26) {
                cur += prev2;
            }
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};
