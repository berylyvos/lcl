#include <string>
#include <algorithm>
using namespace std;
// https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-ii/

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        string t[4];
        for (int i = 0; i < n; ++i) {
            t[i & 1] += s1[i];
            t[(i & 1) + 2] += s2[i];
        }
        for (int i = 0; i < 4; ++i) sort(t[i].begin(), t[i].end());
        return t[0] == t[2] && t[1] == t[3];
    }
};