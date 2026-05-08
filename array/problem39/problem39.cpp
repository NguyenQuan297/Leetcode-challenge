#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    void backtrack(
        vector<int>& candidates, int start, int remaining,
        vector<int>& path, vector<vector<int>>& result
    ) {
        if (remaining == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < static_cast<int>(candidates.size()); ++i) {
            int c = candidates[i];
            if (c > remaining) break;
            path.push_back(c);
            backtrack(candidates, i, remaining - c, path, result);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        backtrack(candidates, 0, target, path, result);
        return result;
    }
};
