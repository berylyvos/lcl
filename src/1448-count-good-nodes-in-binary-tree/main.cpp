#include "headers/tree.h"

// https://leetcode.cn/problems/count-good-nodes-in-binary-tree/

class Solution {
public:
    void dfs(TreeNode *t, int maxi, int &res) {
        if (!t) return;
        if (t->val >= maxi) {
            maxi = t->val;
            ++res;
        }
        dfs(t->left, maxi, res);
        dfs(t->right, maxi, res);
    }

    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, INT_MIN, res);
        return res;
    }
};