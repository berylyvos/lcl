#include "headers/tree.h"
#include <queue>
using namespace std;

// https://leetcode.cn/problems/binary-tree-right-side-view/ 

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (q.size()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto t = q.front();
                q.pop();
                if (i == 0) res.push_back(t->val);
                if (t->right) q.push(t->right);
                if (t->left) q.push(t->left);
            }
        }

        return res;
    }
};