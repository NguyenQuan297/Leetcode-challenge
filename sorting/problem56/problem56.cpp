#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (const auto& inv : intervals) {
            if (res.empty() || inv[0] > res.back()[1]) {
                res.push_back(inv);
            } else {
                res.back()[1] = max(res.back()[1], inv[1]);
            }
        }
        return res;
    }
};
