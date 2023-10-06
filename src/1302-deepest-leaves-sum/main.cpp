#include "headers/tree.h"
// https://leetcode.cn/problems/deepest-leaves-sum/

class Solution {
public:
    int res = 0, d = -1;

    void dfs(TreeNode *t, int u) {
        if (!t) return;
        if (u > d) d = u, res = t->val;
        else if (u == d) res += t->val;
        dfs(t->left, u + 1), dfs(t->right, u + 1);
    }

    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};