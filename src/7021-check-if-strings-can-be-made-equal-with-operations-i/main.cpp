#include <string>
using namespace std;
// https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-i/

class Solution {
public:
    void f(char &c1, char &c2) {
        if (c1 > c2) swap(c1, c2);
    }

    bool canBeEqual(string s1, string s2) {
        f(s1[0], s1[2]);
        f(s1[1], s1[3]);
        f(s2[0], s2[2]);
        f(s2[1], s2[3]);
        return s1 == s2;
    }
};