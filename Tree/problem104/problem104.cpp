#include <algorithm>

// LeetCode already provides TreeNode. For local compile: g++ -std=c++17 -DLOCAL_JUDGE -c problem104.cpp
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
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
