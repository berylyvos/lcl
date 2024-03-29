#include "headers/tree.h"
#include <vector>
#include <unordered_map>
using namespace std;
// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution {
public:
    unordered_map<int, int> pos;

    TreeNode* dfs(vector<int>& in, vector<int>& post, int il, int ir, int pl, int pr) {
        if (il > ir) return nullptr;
        auto root = new TreeNode(post[pr]);
        int mid = pos[post[pr]];
        root->left = dfs(in, post, il, mid - 1, pl, pl + (mid - il) - 1);
        root->right = dfs(in, post, mid + 1, ir, pl + (mid - il), pr - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) pos[inorder[i]] = i;
        return dfs(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};