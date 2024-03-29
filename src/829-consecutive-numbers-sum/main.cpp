// https://leetcode.cn/problems/consecutive-numbers-sum/

class Solution {
public:
    // n = a + a+1 + ... + a+b-1
    // n = (a + a + b - 1) * b / 2
    // 2a = 2n / b - b + 1 > 0
    // 2n / b > b - 1
    // 2n / b >= b
    // 2n >= b * b
    int consecutiveNumbersSum(int n) {
        int res = 0;
        n *= 2;
        for (int b = 1; b * b <= n; ++b)
            if (!(n % b) && !((n / b - b + 1) & 1)) ++res;
        
        return res;
    }
};