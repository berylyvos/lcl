#include <string>
using namespace std;

// https://leetcode.cn/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        string res;
        for (int i = 0; i < s.size();) {
            if (isdigit(s[i])) {
                int k = 0;
                while (s[i] != '[') k = k * 10 + (s[i++] - '0');
                int j = ++i; // '[' j
                int cnt = 0;
                while (cnt >= 0) {
                    if (s[i] == '[') ++cnt;
                    else if (s[i] == ']') --cnt;
                    ++i;
                } // ']' i
                string x = decodeString(s.substr(j, i - j - 1));
                while (k--) res += x;
            } else {
                res += s[i++];
            }
        }

        return res;
    }
};