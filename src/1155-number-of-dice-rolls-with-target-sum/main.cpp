#include <vector>
using namespace std;
// https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/

// 分组背包
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> f(n + 1, vector<int>(target + 1));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= target; ++j)
                for (int u = 1; u <= k && u <= j; ++u)
                    f[i][j] = (f[i][j] + f[i - 1][j - u]) % MOD;

        return f[n][target];
    }
};

// 空间优化
class Solution2 {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<int> f(target + 1);
        f[0] = 1;
        for (int i = 0; i < n; ++i)
            for (int j = target; j >= 0; --j) {
                f[j] = 0;
                for (int u = 1; u <= k && u <= j; ++u)
                    f[j] = (f[j] + f[j - u]) % MOD;
            }

        return f[target];
    }
};