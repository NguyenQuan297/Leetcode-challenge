#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || s.empty()) {
            return {};
        }
        const int wlen = static_cast<int>(words[0].size());
        const int n = static_cast<int>(words.size());
        const int total = wlen * n;
        if (static_cast<int>(s.size()) < total) {
            return {};
        }

        unordered_map<string, int> need;
        need.reserve(words.size() * 2);
        for (const string& w : words) {
            ++need[w];
        }

        vector<int> ans;

        for (int offset = 0; offset < wlen; ++offset) {
            unordered_map<string, int> cur;
            int left = offset;
            int matched = 0;
            for (int j = offset; j + wlen <= static_cast<int>(s.size()); j += wlen) {
                const string word = s.substr(j, wlen);
                auto it = need.find(word);
                if (it != need.end()) {
                    ++cur[word];
                    ++matched;
                    while (cur[word] > it->second) {
                        const string lw = s.substr(left, wlen);
                        if (--cur[lw] == 0) {
                            cur.erase(lw);
                        }
                        --matched;
                        left += wlen;
                    }
                    if (matched == n) {
                        ans.push_back(left);
                        const string lw = s.substr(left, wlen);
                        if (--cur[lw] == 0) {
                            cur.erase(lw);
                        }
                        --matched;
                        left += wlen;
                    }
                } else {
                    cur.clear();
                    matched = 0;
                    left = j + wlen;
                }
            }
        }

        return ans;
    }
};
