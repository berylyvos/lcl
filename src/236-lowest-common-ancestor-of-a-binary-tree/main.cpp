#include "headers/tree.h"

// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        auto l = lowestCommonAncestor(root->left, p, q), 
            r = lowestCommonAncestor(root->right, p, q);
        if (!l) return r;
        if (!r) return l;
        return root;
    }
};