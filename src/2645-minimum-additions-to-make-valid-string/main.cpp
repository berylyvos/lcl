#include <string>
using namespace std;
// https://leetcode.cn/problems/minimum-additions-to-make-valid-string

class Solution {
public:
    int addMinimum(string word) {
        string s = "abc";
        int res = 0, n = word.size();
        for (int i = 0, j = 0; i < n; j = (j + 1) % 3) {
            if (word[i] == s[j]) {
                ++i;
            } else {
                ++res;
            }
        }
        if (word[n - 1] != 'c') {
            res += word[n - 1] == 'a' ? 2 : 1;
        }
        return res; 
    }
};