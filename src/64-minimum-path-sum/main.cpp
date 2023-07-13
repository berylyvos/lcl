#include <vector>
using namespace std;

// https://leetcode.cn/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 1e8));
        f[0][1] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i - 1][j - 1];
        
        return f[n][m];
    }
};