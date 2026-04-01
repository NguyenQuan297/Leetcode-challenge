#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // Sort to group duplicates; avoid picking same value twice at the same depth
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        dfs(nums, used, path, res);
        return res;
    }

private:
    void dfs(const vector<int>& nums, vector<bool>& used, vector<int>& path,
             vector<vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            if (i > 0 && !used[i - 1] && nums[i] == nums[i - 1]) {
                // Same value as previous which is not used in this position -> duplicate permutation
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, used, path, res);
            path.pop_back();
            used[i] = false;
        }
    }
};
