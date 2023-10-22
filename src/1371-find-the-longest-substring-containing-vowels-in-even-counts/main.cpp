#include <vector>
#include <string>
using namespace std;
// https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/

class Solution {
public:
    const string ae = "aeiou";
    
    int findTheLongestSubstring(string s) {
        int res = 0;
        // a, e, i, o, u 出现次数的奇偶状态共有 2^5 种
        // f[i]：状态为 i 的 s子串， 当该状态第一次出现时，子串结尾下标为 f[i]
        vector<int> f(32, -2);
        f[0] = -1;
        for (int i = 0, state = 0; i < s.size(); ++i) {
            int k = ae.find(s[i]);
            if (k != -1) state ^= 1 << k;
            if (f[state] == -2) f[state] = i;
            else res = max(res, i - f[state]);
        }
        return res;
    }
};