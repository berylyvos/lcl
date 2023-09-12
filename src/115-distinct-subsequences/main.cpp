#include <string>
#include <vector>
using namespace std;
// https://leetcode.cn/problems/distinct-subsequences/

class Solution {
public:
    int numDistinct(string s, string t) {
        const int MOD = 1e9 + 7;
        int n = s.size(), m = t.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; ++i) f[i][0] = 1;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                f[i][j] = f[i - 1][j];
                if (s[i - 1] == t[j - 1])
                    f[i][j] = (f[i][j] + f[i - 1][j - 1]) % MOD;
            }
        
        return f[n][m];
    }
};