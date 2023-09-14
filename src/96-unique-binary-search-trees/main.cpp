#include <vector>
using namespace std;
// https://leetcode.cn/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        // f[i]: 节点数为 i 的不同二叉搜索树的方案数
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) // 枚举节点个数
            for (int j = 1; j <= i; ++j) // 枚举root
                f[i] += f[j - 1] * f[i - j];
        return f[n];
    }
};