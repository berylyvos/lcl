#include <vector>
using namespace std;

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/

// O(kn)
class Solution3 {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(), res = 0;
        if (k >= n / 2) {
            for (int i = 1; i < n; i++)
                res += max(0, prices[i] - prices[i - 1]);
            return res;
        }

        vector<vector<int>> f(n + 1, vector<int>(k + 1, -1e8));
        auto g = f;
        // f[i][j]: 经过 i 天做了 j 笔交易
        // g[i][j]: 经过 i 天正在做第 j 笔交易（已买入，未卖出
        // 
        //   == -w ===> g
        // f <== +w ===
        
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j <= k; ++j) {
                f[i][j] = max(f[i - 1][j], g[i - 1][j] + prices[i - 1]);
                g[i][j] = g[i - 1][j];
                if (j > 0) g[i][j] = max(g[i][j], f[i - 1][j - 1] - prices[i - 1]);
                res = max(res, f[i][j]);
            }
        
        return res;
    }
};

// O(kn)
class Solution2 {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> f(n + 1, vector<int>(k + 1));

        for (int j = 1; j <= k; ++j) {
            int t = f[0][j - 1] - prices[0];
            for (int i = 1; i <= n; ++i) {
                f[i][j] = max(f[i - 1][j], t + prices[i - 1]);
                t = max(t, f[i - 1][j - 1] - prices[i - 1]);
            }
        }
        return f[n][k];
    }
};

// O(k * n^2)  TLE
class SolutionTLE {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        // f[i][j]: 前 i 天 进行了 j 次交易的最大利润
        // 按最后一笔交易分情况：
        // a. 不在第 i 天卖出，f[i][j] = f[i - 1][j]
        // b. 在第 i 天卖出，枚举买入时间 u(0 < u < i)
        //    f[i][j] = max(f[u - 1][j - 1] - prices[u]) + prices[i]

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= k; ++j) {
                f[i][j] = f[i - 1][j];
                for (int u = 1; u < i; ++u)
                    f[i][j] = max(f[i][j], f[u - 1][j - 1] - prices[u - 1] + prices[i - 1]);
            }
        
        return f[n][k];
    }
};