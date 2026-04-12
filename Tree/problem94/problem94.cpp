#include <stack>
#include <vector>

using namespace std;

// LeetCode already provides TreeNode. For local compile: g++ -std=c++17 -DLOCAL_JUDGE -c problem94.cpp
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
    vector<int> inorderTraversal(TreeNode *root) {
        // Iterative inorder (Left -> Root -> Right): descend left pushing nodes, then pop, visit, go right.
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};