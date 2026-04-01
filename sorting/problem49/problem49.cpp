#include <array>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct KeyHash {
    size_t operator()(const array<int, 26>& a) const noexcept {
        size_t h = 0;
        for (int v : a) {
            h = h * 1315423911u + static_cast<unsigned>(v + 1);
        }
        return h;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, KeyHash> mp;
        for (const string& s : strs) {
            array<int, 26> cnt{};
            for (char ch : s) {
                cnt[ch - 'a']++;
            }
            mp[cnt].push_back(s);
        }
        vector<vector<string>> res;
        res.reserve(mp.size());
        for (auto& kv : mp) {
            res.push_back(move(kv.second));
        }
        return res;
    }
};
