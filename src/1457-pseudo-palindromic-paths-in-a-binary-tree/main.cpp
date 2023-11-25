#include "headers/tree.h"
// https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree/

class Solution {
public:
    int res = 0;

    void dfs(TreeNode *t, int cnt) {
        if (!t) return;
        cnt ^= 1 << t->val;

        if (!t->left && !t->right) {
            // cnt: 0...000
            // cnt: 0...010...0
            res += (!cnt || cnt == (cnt & -cnt));
        }

        dfs(t->left, cnt);
        dfs(t->right, cnt);
        cnt ^= 1 << t->val;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};