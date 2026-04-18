#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        static const unordered_map<char, int> sym{
            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000},
        };
        int total = 0;
        const int n = static_cast<int>(s.size());
        for (int i = 0; i < n; ++i) {
            const int v = sym.at(s[i]);
            if (i + 1 < n && v < sym.at(s[i + 1])) {
                total -= v;
            } else {
                total += v;
            }
        }
        return total;
    }
};
