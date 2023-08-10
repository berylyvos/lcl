#include <string>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/longest-palindromic-subsequence/
// 区间DP
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, 0));

        for (int sz = 1; sz <= n; ++sz)
            for (int i = 0, j = i + sz - 1; j < n; ++i, ++j) {
                if (sz == 1) f[i][j] = 1;
                else {
                    if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1] + 2;
                    else f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                }
            }
        
        return f[0][n - 1];
    }
};