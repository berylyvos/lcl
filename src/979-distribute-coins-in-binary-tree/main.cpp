#include "headers/tree.h"
using namespace std;
// https://leetcode.cn/problems/distribute-coins-in-binary-tree/

class Solution {
public:
    tuple<int, int, int> dfs(TreeNode* t) {
        if (!t) return {0, 0, 0};
        auto [ln, lm, lr] = dfs(t->left);
        auto [rn, rm, rr] = dfs(t->right);
        int n = ln + rn + 1, m = lm + rm + t->val;
        return {n, m, abs(n - m) + lr + rr};
    }

    int distributeCoins(TreeNode* root) {
        return get<2>(dfs(root));
    }
};