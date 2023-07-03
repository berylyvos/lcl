#include "headers/tree.h"
#include <unordered_map>
using namespace std;

// https://leetcode.cn/problems/path-sum-iii/

class Solution {
public:
    using LL = long long;
    int target, res = 0;
    unordered_map<LL, int> cnt; // count for prefix sum

    void dfs(TreeNode *t, LL s) {
        if (!t) return;
        s += t->val;
        res += cnt[s - target];
        cnt[s]++;
        dfs(t->left, s);
        dfs(t->right, s);
        cnt[s]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        cnt[0] = 1;
        dfs(root, 0);
        return res;
    }
};