#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Vertical scan: all strings must share the same character at each index
        if (strs.empty()) {
            return "";
        }
        const string& ref = strs[0];
        for (size_t i = 0; i < ref.size(); ++i) {
            char c = ref[i];
            for (size_t j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return ref.substr(0, i);
                }
            }
        }
        return ref;
    }
};
