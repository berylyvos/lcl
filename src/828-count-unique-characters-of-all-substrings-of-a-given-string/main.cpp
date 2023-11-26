#include <vector>
#include <string>
using namespace std;
// https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/

class Solution {
public:
    static const int A = 'A';

    int uniqueLetterString(string s) {
        int n = s.size(), res = 0;
        vector<int> l(n), p(26, -1);
        for (int i = 0; i < n; ++i) {
            l[i] = p[s[i] - A];
            p[s[i] - A] = i;
        }
        p.assign(26, n);
        for (int i = n - 1, ri; ~i; --i) {
            ri = p[s[i] - A];
            p[s[i] - A] = i;
            res += (i - l[i]) * (ri - i);
        }
        return res;
    }
};