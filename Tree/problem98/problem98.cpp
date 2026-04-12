#include <climits>
#include <stack>

using namespace std;

// LeetCode already provides TreeNode. For local compile: g++ -std=c++17 -DLOCAL_JUDGE -c problem98.cpp
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
    bool isValidBST(TreeNode *root) {
        // Inorder of a BST is strictly increasing. One stack walk, no std::function / deep recursion.
        long long prev = (long long)INT_MIN - 1;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (cur->val <= prev) {
                return false;
            }
            prev = cur->val;
            cur = cur->right;
        }
        return true;
    }
};
