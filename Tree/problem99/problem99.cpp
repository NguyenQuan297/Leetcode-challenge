#include <utility>

using namespace std;

// LeetCode already provides TreeNode. For local compile: g++ -std=c++17 -DLOCAL_JUDGE -c problem99.cpp
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
    void recoverTree(TreeNode *root) {
        // Morris inorder (O(1) extra space): two swaps break sorted order; track first and second anomalies.
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        TreeNode *prev = nullptr;
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *pre = cur->left;
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    if (prev && prev->val > cur->val) {
                        if (!first) {
                            first = prev;
                        }
                        second = cur;
                    }
                    prev = cur;
                    pre->right = nullptr;
                    cur = cur->right;
                }
            } else {
                if (prev && prev->val > cur->val) {
                    if (!first) {
                        first = prev;
                    }
                    second = cur;
                }
                prev = cur;
                cur = cur->right;
            }
        }
        swap(first->val, second->val);
    }
};
