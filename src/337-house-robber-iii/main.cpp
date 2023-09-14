#include <cstdio>
#include "headers/tree.h"

using namespace std;

class Solution {
public:
    // <不偷当前节点，偷...>
    pair<int, int> dfs(TreeNode* t) {
        if (!t) return {0, 0};
        auto [l1, l2] = dfs(t->left);
        auto [r1, r2] = dfs(t->right);
        return {max(l1, l2) + max(r1, r2), t->val + l1 + r1};
    }

    int rob(TreeNode* root) {
        auto [a, b] = dfs(root);
        return max(a, b);
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