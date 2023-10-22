#include <vector>
#include "headers/tree.h"
using namespace std;
// https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/

class Solution {
public:
    const int INF = 1e8;
    int res = 0;

    // <sum, min, max>
    vector<int> dfs(TreeNode* t) {
        int x = t->val;
        vector<int> l{0, x, -INF};
        vector<int> r{0, INF, x};
        if (t->left) l = dfs(t->left);
        if (t->right) r = dfs(t->right);

        if (l[0] != -INF && r[0] != -INF && l[2] < x && x < r[1]) {
            int s = l[0] + r[0] + x;
            res = max(res, s);
            return {s, l[1], r[2]};
        }
        return {-INF, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return res;
    }
};