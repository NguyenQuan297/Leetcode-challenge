#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    void backtrack(
        vector<int>& nums, int start,
        vector<int>& path, vector<vector<int>>& result
    ) {
        result.push_back(path);
        for (int i = start; i < static_cast<int>(nums.size()); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;  // skip duplicates
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, result);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        backtrack(nums, 0, path, result);
        return result;
    }
};
