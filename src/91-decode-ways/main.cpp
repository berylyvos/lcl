#include <cstdio>
#include <vector>
#include <string>
using namespace std;
// https://leetcode.cn/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int n = s.size();
        s = ' ' + s;
        vector<int> f(n + 1);
        f[0] = 1, f[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (s[i] != '0') f[i] = f[i - 1];
            if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] <= '6')) f[i] += f[i - 2];
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