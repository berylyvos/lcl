#include "headers/tree.h"
#include <algorithm>
using namespace std;

// https://leetcode.cn/problems/longest-zigzag-path-in-a-binary-tree/

class Solution {
public:
    int res = 0;

    int dfs(TreeNode* t, bool left) {
        if (!t) return 0;
        int l = dfs(t->left, true), r = dfs(t->right, false);
        res = max({res, l, r});
        return left ? r + 1 : l + 1;
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, true);
        return res;
    }
};