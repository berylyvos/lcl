#include "headers/tree.h"
#include <queue>
using namespace std;
// https://leetcode.cn/problems/cousins-in-binary-tree

// DFS
class Solution {
public:
    vector<int> dfs(TreeNode *t, int v, int fv, int d) {
        if (!t) return {0, 0};
        if (t->val == v) return {fv, d};
        auto l = dfs(t->left, v, t->val, d + 1);
        auto r = dfs(t->right, v, t->val, d + 1);
        return {l[0] + r[0], l[1] + r[1]};
    }

    bool isCousins(TreeNode* root, int x, int y) {
        auto a = dfs(root, x, -1, 0);
        auto b = dfs(root, y, -1, 0);
        return a[0] != b[0] && a[1] == b[1];
    }
};

// BFS
class Solution1 {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (x == root->val || y == root->val) return false;
        queue<TreeNode*> q;
        q.push(root);
        int d = 0;
        pair<TreeNode*, int> a, b;
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                auto t = q.front(); q.pop();
                if (t->left) {
                    if (t->left->val == x) {
                        a.first = t;
                        a.second = d;
                    }
                    if (t->left->val == y) {
                        b.first = t;
                        b.second = d;
                    }
                    q.push(t->left);
                }
                if (t->right) {
                    if (t->right->val == x) {
                        a.first = t;
                        a.second = d;
                    }
                    if (t->right->val == y) {
                        b.first = t;
                        b.second = d;
                    }
                    q.push(t->right);
                }
            }
            ++d;
        }
        return a.first != b.first && a.second == b.second;
    }
};