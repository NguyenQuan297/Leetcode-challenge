#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        static const unordered_map<int, string> thousands{
            {0, ""}, {1, "M"}, {2, "MM"}, {3, "MMM"}};
        static const unordered_map<int, string> hundreds{
            {0, ""},  {1, "C"},  {2, "CC"},  {3, "CCC"}, {4, "CD"},
            {5, "D"},  {6, "DC"}, {7, "DCC"}, {8, "DCCC"}, {9, "CM"}};
        static const unordered_map<int, string> tens{
            {0, ""},  {1, "X"},  {2, "XX"},  {3, "XXX"}, {4, "XL"},
            {5, "L"},  {6, "LX"}, {7, "LXX"}, {8, "LXXX"}, {9, "XC"}};
        static const unordered_map<int, string> ones{
            {0, ""},  {1, "I"},  {2, "II"},  {3, "III"}, {4, "IV"},
            {5, "V"},  {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"}};

        return thousands.at(num / 1000) + hundreds.at((num % 1000) / 100)
            + tens.at((num % 100) / 10) + ones.at(num % 10);
    }
};
