#include <string>
using namespace std;

// https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// LCS alternative
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int f[n + 1][n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i)
            for (int j = n - 1; ~j; --j)
                if (s[i - 1] == s[j]) f[i][j] = f[i - 1][j + 1] + 1;
                else f[i][j] = max(f[i - 1][j], f[i][j + 1]);
        
        return n - f[n][0];
    }
};

// interval dp
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int sz = 2; sz <= n; ++sz)
            for (int i = 0, j = i + sz - 1; j < n; ++i, ++j) {
                if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1];
                else f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
            }
        return f[0][n - 1];
    }
};