#include "headers/tree.h"
#include <algorithm>
using namespace std;

// https://leetcode.cn/problems/longest-zigzag-path-in-a-binary-tree/

class Solution {
public:
    int res = 0;

    void dfs(TreeNode *t, bool left, int s) {
        if (!t) return;
        res = max(res, s);

        dfs(t->left,  true,  left ? 1 : s + 1);
        dfs(t->right, false, left ? s + 1 : 1);     
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, false, 0);
        return res;
    }
};