#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// https://leetcode.cn/problems/ones-and-zeroes

// 二维01背包
// 我的题解：https://leetcode.cn/problems/ones-and-zeroes/solutions/2443337/er-wei-01bei-bao-c-9671-9614-by-bryce22-awps/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int f[m + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (auto& s: strs) {
            int c0 = count(s.begin(), s.end(), '0'), c1 = s.size() - c0;
            for (int i = m; i >= c0; --i)
                for (int j = n; j >= c1; --j)
                    f[i][j] = max(f[i][j], f[i - c0][j - c1] + 1);
        }
        return f[m][n];
    }
};