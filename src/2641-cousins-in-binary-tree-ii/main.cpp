#include <vector>
#include "headers/tree.h"
using namespace std;
// https://leetcode.cn/problems/cousins-in-binary-tree-ii

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        vector<TreeNode*> q = {root};
        while (q.size()) {
            vector<TreeNode*> q2;
            int s = 0;
            for (auto p: q) {
                if (p->left) {
                    q2.push_back(p->left);
                    s += p->left->val;
                }
                if (p->right) {
                    q2.push_back(p->right);
                    s += p->right->val;
                }
            }
            for (auto p: q) {
                int t = s - (p->left ? p->left->val : 0) -
                            (p->right ? p->right->val : 0);
                if (p->left) {
                    p->left->val = t;
                }
                if (p->right) {
                    p->right->val = t;
                }
            }
            q = move(q2);
        }
        return root;  
    }
};