#include <vector>
#include <string>
using namespace std;
// https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1));

        int s = 0;
        for (auto &x: s1) s += x; 
        for (auto &x: s2) s += x; 

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
                if (s1[i - 1] == s2[j - 1]) 
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + s1[i - 1] * 2); 
            }
        
        return s - f[n][m];
    }
};