// LeetCode already provides TreeNode. For local compile: g++ -std=c++17 -DLOCAL_JUDGE -c problem101.cpp
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
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return mirror(root->left, root->right);
    }

private:
    bool mirror(TreeNode *a, TreeNode *b) {
        if (!a && !b) {
            return true;
        }
        if (!a || !b) {
            return false;
        }
        if (a->val != b->val) {
            return false;
        }
        return mirror(a->left, b->right) && mirror(a->right, b->left);
    }
};
