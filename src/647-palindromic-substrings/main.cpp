#include <string>
using namespace std;

// https://leetcode.cn/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        
        for (int i = 0; i < n; ++i) {
            // 回文长度为奇数，枚举中心点
            for (int l = i, r = i; ~l && r < n; --l, ++r)
                if (s[l] == s[r]) ++res;
                else break;
        
            // 回文长度为偶数，枚举中心左侧点
            for (int l = i, r = i + 1; ~l && r < n; --l, ++r)
                if (s[l] == s[r]) ++res;
                else break;
        }
        
        return res;
    }
};