#include <vector>
#include <cstring>
using namespace std;

// https://leetcode.cn/problems/perfect-squares/

// 求由若干完全平方数组成n的最小个数
// => 
// 完全背包 求总体积恰为背包容量的最小价值
class Solution {
public:
    int numSquares(int n) {
        vector<int> w;
        for (int i = 1; i * i <= n; ++i) w.push_back(i * i);

        int m = w.size();
        int f[n + 1];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < m; ++i)
            for (int j = w[i]; j <= n; ++j)
                f[j] = min(f[j], f[j - w[i]] + 1); 
        
        return f[n];
    }
};