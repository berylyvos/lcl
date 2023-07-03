#include "headers/tree.h"
#include <vector>
using namespace std;

// https://leetcode.cn/problems/leaf-similar-trees

class Solution {
public:
    void dfs(TreeNode *t, vector<int> &a) {
        if (!t) return;
        if (!t->left && !t->right) a.push_back(t->val);
        dfs(t->left, a);
        dfs(t->right, a);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        dfs(root1, a);
        dfs(root2, b);
        return a == b;
    }
};