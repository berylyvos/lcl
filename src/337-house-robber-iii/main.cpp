#include <cstdio>
#include "headers/tree.h"

using namespace std;

class Solution {
public:
    // <偷当前节点，不偷当前节点>
    pair<int, int> dfs(TreeNode *cur) {
        if (!cur) return {0, 0};
        auto l = dfs(cur->left), r = dfs(cur->right);
        return make_pair(cur->val + l.second + r.second, max(l.first, l.second) + max(r.first, r.second));
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};

int main() {
    //   3
    // 2   3
    //  3   1
    auto root = deserializeTree("3,2,3,null,3,null,1"); 
    printf("%d\n", Solution().rob(root)); // 7
    destroyTree(root);
    return 0;
}