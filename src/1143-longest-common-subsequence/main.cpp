#include <vector>
#include <string>
using namespace std;

// https://leetcode.cn/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1));

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (s[i - 1] == t[j - 1])
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        
        return f[n][m];
    }
};