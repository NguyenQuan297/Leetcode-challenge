#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Backtracking with in-place swaps to generate all n! permutations
        vector<vector<int>> res;
        dfs(0, nums, res);
        return res;
    }

private:
    void dfs(int first, vector<int>& nums, vector<vector<int>>& res) {
        if (first == static_cast<int>(nums.size())) {
            res.push_back(nums);
            return;
        }
        for (int i = first; i < static_cast<int>(nums.size()); ++i) {
            swap(nums[first], nums[i]);
            dfs(first + 1, nums, res);
            swap(nums[first], nums[i]);
        }
    }
};
