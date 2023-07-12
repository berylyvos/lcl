#include <string>
using namespace std;

// https://leetcode.cn/problems/nth-digit/

class Solution {
public:
    int findNthDigit(int n) {
        long long s = 1, t = 9;
        // [1,   9].   9.   1*9
        // [10,  99].  90.  2*90
        // [100, 999]. 900. 3*900
        // ...
        
        // 计算 x 的位数 k
        int k = 1;
        while (n > k * t) {
            n -= k * t;
            ++k, s *= 10, t *= 10;
        }

        // 计算 x 是 k位数字的第几个，s加上它得到x
        s += (n + k - 1) / k - 1;

        // 是 x 的 Nth-digit
        n = n % k ? n % k : k;
        return to_string(s)[n - 1] - '0';
    }
};