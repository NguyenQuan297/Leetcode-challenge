#include <functional>
#include <map>
#include <utility>
#include <vector>

using namespace std;

// LeetCode already provides TreeNode. For local compile: g++ -std=c++17 -DLOCAL_JUDGE -c problem95.cpp
#ifdef LOCAL_JUDGE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        // Memoize trees for each value range; clone left/right when forming a new root so
        // each answer tree owns its own nodes (no sharing across the result list).
        function<TreeNode *(TreeNode *)> clone = [&](TreeNode *root) -> TreeNode * {
            if (!root) {
                return nullptr;
            }
            return new TreeNode(root->val, clone(root->left), clone(root->right));
        };

        map<pair<int, int>, vector<TreeNode *>> memo;

        function<vector<TreeNode *>(int, int)> gen = [&](int start, int end) -> vector<TreeNode *> {
            if (start > end) {
                return {nullptr};
            }
            pair<int, int> key = {start, end};
            auto it = memo.find(key);
            if (it != memo.end()) {
                return it->second;
            }
            vector<TreeNode *> res;
            for (int i = start; i <= end; ++i) {
                for (TreeNode *l : gen(start, i - 1)) {
                    for (TreeNode *r : gen(i + 1, end)) {
                        res.push_back(new TreeNode(i, clone(l), clone(r)));
                    }
                }
            }
            memo[key] = res;
            return res;
        };

        return gen(1, n);
    }
};
