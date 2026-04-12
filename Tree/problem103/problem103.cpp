#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// LeetCode already provides TreeNode. For local compile: g++ -std=c++17 -DLOCAL_JUDGE -c problem103.cpp
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int sz = static_cast<int>(q.size());
            vector<int> level;
            for (int i = 0; i < sz; ++i) {
                TreeNode *n = q.front();
                q.pop();
                level.push_back(n->val);
                if (n->left) {
                    q.push(n->left);
                }
                if (n->right) {
                    q.push(n->right);
                }
            }
            if (depth % 2 == 1) {
                reverse(level.begin(), level.end());
            }
            res.push_back(level);
            ++depth;
        }
        return res;
    }
};
