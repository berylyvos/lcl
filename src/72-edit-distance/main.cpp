#include <string>
using namespace std;

// https://leetcode.cn/problems/edit-distance/

class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();
        if (!n || !m) return n + m;
        int f[n + 1][m + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) f[i][0] = i;
        for (int i = 1; i <= m; ++i) f[0][i] = i;

        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j)
        {
            // 删除 a[i]: f[i - 1][j] + 1
            // a[i] 后添加 b[j]: f[i][j - 1] + 1
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            // 编辑 a[i]
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }

        return f[n][m];
    }
};