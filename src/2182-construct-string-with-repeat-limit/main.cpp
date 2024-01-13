#include <string>
using namespace std;
// https://leetcode.cn/problems/construct-string-with-repeat-limit

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        const char a = 'a';
        int cnt[26]{};
        for (char& c: s) ++cnt[c - a];
        string res;
        for (int i = 25, j = 24; ~i; --i) {
            j = min(j, i - 1);
            while (true) {
                int k = min(cnt[i], repeatLimit);
                res.append(k, a + i);
                cnt[i] -= k;
                if (!cnt[i]) break;
                
                while (~j && !cnt[j]) --j;
                if (j < 0) break;
                res += a + j;
                --cnt[j];
            }
        }
        return res;
    }
};