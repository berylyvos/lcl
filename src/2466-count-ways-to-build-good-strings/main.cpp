#include <cstring>
using namespace std;
// https://leetcode.cn/problems/count-ways-to-build-good-strings

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        int f[high + 1], res = 0;
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= high; ++i) {
            if (i >= zero) f[i] = (f[i] + f[i - zero]) % MOD; 
            if (i >= one) f[i] = (f[i] + f[i - one]) % MOD;
            if (i >= low) res = (res + f[i]) % MOD;
        }
        return res;
    }
};