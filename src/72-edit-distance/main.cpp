#include <vector>
#include <string>
using namespace std;

// https://leetcode.cn/problems/edit-distance/

class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();
        if (!n || !m) return n + m;
        // f[i][j]: a[1, i] 与 b[1, j] 的最短编辑距离
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) f[i][0] = i;
        for (int i = 1; i <= m; ++i) f[0][i] = i;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                // 删除 / 添加
                f[i][j] = min(f[i][j - 1] + 1, f[i - 1][j] + 1);

                // 替换
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i - 1] != b [j - 1]));
            }
        
        return f[n][m];
    }
};