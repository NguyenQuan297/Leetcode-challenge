#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        static const int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        static const char* syms[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",  "XL", "X",  "IX", "V",  "IV", "I"};
        string res;
        res.reserve(16);
        for (int i = 0; i < 13; ++i) {
            while (num >= vals[i]) {
                res += syms[i];
                num -= vals[i];
            }
        }
        return res;
    }
};
