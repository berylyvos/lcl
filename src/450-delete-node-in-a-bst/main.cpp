#include "headers/tree.h"

// https://leetcode.cn/problems/delete-node-in-a-bst/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        auto t = root;
        if (!t) return nullptr;
        
        if (t->val > key) t->left = deleteNode(t->left, key);
        else if (t->val < key) t->right = deleteNode(t->right, key);
        else {
            if (!t->left && !t->right) t = nullptr;
            else if (!t->left) t = t->right;
            else if (!t->right) t = t->left;
            else {
                auto p = t->right;
                while (p->left) p = p->left;
                t->val = p->val;
                t->right = deleteNode(t->right, t->val);
            }
        }

        return t;
    }
};