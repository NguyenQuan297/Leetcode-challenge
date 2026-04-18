#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        need.reserve(t.size() * 2);
        for (char c : t) {
            ++need[c];
        }
        int missing = static_cast<int>(t.size());
        int left = 0;
        int start = 0;
        int best = INT_MAX;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            char ch = s[right];
            if (need[ch] > 0) {
                --missing;
            }
            --need[ch];
            while (missing == 0) {
                const int len = right - left + 1;
                if (len < best) {
                    best = len;
                    start = left;
                }
                const char c = s[left];
                if (need[c] == 0) {
                    ++missing;
                }
                ++need[c];
                ++left;
            }
        }

        return best == INT_MAX ? "" : s.substr(start, best);
    }
};
