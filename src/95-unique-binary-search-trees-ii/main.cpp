#include <vector>
#include "headers/tree.h"
using namespace std;
// https://leetcode.cn/problems/unique-binary-search-trees-ii

class Solution {
public:
    vector<TreeNode*> dfs(int l, int r) {
        if (l > r) return vector<TreeNode*>{nullptr};
        
        vector<TreeNode*> res;
        for (int i = l; i <= r; ++i) {
            auto left = dfs(l, i - 1), right = dfs(i + 1, r);
            for (auto lt: left) 
                for (auto rt: right) {
                    auto root = new TreeNode(i, lt, rt);
                    res.push_back(root);
                }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }
};