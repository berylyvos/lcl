#include <string>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), r, l;
        string res;
        for (int i = 0; i < n; ++i) {
            l = i - 1, r = i + 1;
            while (~l && r < n && s[l] == s[r]) --l, ++r;
            if (r - l - 1 > res.size()) res = s.substr(l + 1, r - l - 1);

            l = i, r = i + 1;
            while (~l && r < n && s[l] == s[r]) --l, ++r;
            if (r - l - 1 > res.size()) res = s.substr(l + 1, r - l - 1);
        }
        return res;
    }
};

class Solution2 {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, len = 0;
        vector<vector<bool>> f(n, vector<bool>(n, false));

        for (int sz = 1; sz <= n; ++sz)
            for (int i = 0; i + sz - 1 < n; ++i) {
                int j = i + sz - 1;
                if (sz == 1) f[i][j] = true;
                else if (sz == 2) f[i][j] = s[i] == s[j];
                else f[i][j] = f[i + 1][j - 1] && (s[i] == s[j]);
                if (f[i][j] && j - i + 1 > len) {
                    len = j - i + 1;
                    start = i;
                }
            }

        return s.substr(start, len);
    }
};