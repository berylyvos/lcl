#include <vector>
using namespace std;

// https://leetcode.cn/problems/domino-and-tromino-tiling/

class Solution {
public:
    int numTilings(int n) {
        // f[i][j]: 前 i - 1 列已铺满，且第 i 列的状态为 j 的方法数
        vector<vector<int>> f(n + 1, vector<int>(4));
        f[0][0] = 1;
        /*          f[i + 1] 
                    00   01   10   11
            f[i] 
             00      1    1    1    1
             01                1    1
             10           1         1
             11      1                 
        */
        int w[4][4] = {
            {1, 1, 1, 1},
            {0, 0, 1, 1},
            {0, 1, 0, 1},
            {1, 0, 0, 0}
        };

        const int MOD = 1e9 + 7;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 4; ++j)
                for (int k = 0; k < 4; ++k)
                    f[i + 1][k] = (f[i + 1][k] + f[i][j] * w[j][k]) % MOD;
        
        return f[n][0]; 
    }
};