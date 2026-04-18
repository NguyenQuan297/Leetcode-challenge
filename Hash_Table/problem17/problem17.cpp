#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        static const unordered_map<char, string> pad{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
        };
        vector<string> out;
        out.emplace_back("");
        for (char d : digits) {
            const string& letters = pad.at(d);
            vector<string> nxt;
            nxt.reserve(out.size() * letters.size());
            for (const string& p : out) {
                for (char c : letters) {
                    nxt.push_back(p + c);
                }
            }
            out = std::move(nxt);
        }
        return out;
    }
};
