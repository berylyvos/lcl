#include <string>
using namespace std;

// https://leetcode.cn/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        string res;
        for (int i = n - 1, j = m - 1, t = 0; i >= 0 || j >= 0 || t > 0;) {
            if (i >= 0) t += num1[i--] - '0';
            if (j >= 0) t += num2[j--] - '0';
            res.push_back(t % 10 + '0');
            t /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};