#include <string>
using namespace std;

// 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        for (; i < t.size(); ++i) {
            if (t[i] == s[j])
                if (++j == s.size())
                    return true;
        }
        return j == s.size();
    }
};