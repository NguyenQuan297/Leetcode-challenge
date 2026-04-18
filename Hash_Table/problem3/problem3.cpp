#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last;
        int left = 0;
        int best = 0;
        const int n = static_cast<int>(s.size());
        for (int right = 0; right < n; ++right) {
            const char ch = s[right];
            auto it = last.find(ch);
            if (it != last.end() && it->second >= left) {
                left = it->second + 1;
            }
            last[ch] = right;
            best = max(best, right - left + 1);
        }
        return best;
    }
};
