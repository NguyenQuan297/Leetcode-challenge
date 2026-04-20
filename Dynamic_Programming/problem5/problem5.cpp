#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = static_cast<int>(s.size());
        if (n <= 1) {
            return s;
        }

        int start = 0;
        int maxLen = 0;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    maxLen = len;
                    start = left;
                }
                --left;
                ++right;
            }
        };

        for (int i = 0; i < n; ++i) {
            expand(i, i);
            expand(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};
