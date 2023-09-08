#include <vector>
using namespace std;
// https://leetcode.cn/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0, m = 0;
        vector<int> f(n, 1), g(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i]) {
                    if (f[j] + 1 > f[i]) f[i] = f[j] + 1, g[i] = g[j];
                    else if (f[j] + 1 == f[i]) g[i] += g[j];
                }
            m = max(m, f[i]);
        }
        
        for (int i = 0; i < n; ++i) if (f[i] == m) res += g[i];
        
        return res;
    }
};