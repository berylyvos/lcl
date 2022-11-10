#include <cstdio>
#include "headers/tree.h"

using namespace std;

class Solution {
public:
    int ans;

    // 返回cur向左（右）子树延伸，或不延伸的最大路径和
    int dfs(TreeNode *cur) {
        if (!cur) return 0;
        int left = dfs(cur->left), right = dfs(cur->right);
        ans = max(ans, left + right + cur->val);
        return max(0, max(left, right) + cur->val);
    }
     
    int maxPathSum(TreeNode* root) {
        ans = 0x80000000;
        dfs(root);
        return ans;
    }
};

int main()
{
    //      -10
    //   9        20
    //         15    7
    auto root = deserializeTree("-10,9,20,null,null,15,7");
    printf("%d\n", Solution().maxPathSum(root)); //  15 -> 20 -> 7 ，42
    destroyTree(root);

    //      0
    //   0     0
    root = deserializeTree("0,0,0");
    printf("%d\n", Solution().maxPathSum(root)); // 0
    destroyTree(root);

    //      -99
    //   -1      0
    // -2     -1
    root = deserializeTree("-99,-1,0,-2,null,-1,null");
    printf("%d\n", Solution().maxPathSum(root)); // 0
    destroyTree(root);

    return 0;
}