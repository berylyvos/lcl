#include "headers/tree.h"

// https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/

class Solution {
public:
    std::pair<TreeNode*, int> dfs(TreeNode* t) {
        if (!t) return {nullptr, 0};
        auto [l, ld] = dfs(t->left);
        auto [r, rd] = dfs(t->right);
        if (ld == rd) return {t, ld + 1};
        else if (ld > rd) return {l, ld + 1};
        else return {r, rd + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};