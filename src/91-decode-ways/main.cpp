#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        s = ' ' + s;
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++ i) {
            int num = s[i] - '0';
            if (num != 0) f[i] = f[i - 1]; // 当前字母单独解码
            if (i > 1 && s[i - 1] != '0') {
                num = (s[i - 1] - '0') * 10 + num;
                if (num <= 26) f[i] += f[i - 2]; // 当前字母和前一个字母合起来解码
            }
        }
        return f[n];
    }
};

int main() {
    // 2, 2, 6
    // 22, 6
    // 2, 26
    printf("%d\n", Solution().numDecodings("226"));
    return 0;
}