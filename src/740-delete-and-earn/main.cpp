#include <vector>
using namespace std;

// https://leetcode.cn/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size(), m = 0;
        vector<int> cnt(10001);
        for (auto& x: nums) cnt[x]++, m = max(m, x);

        vector<int> f(m + 1), g(m + 1);
        for (int i = 1; i <= m; ++i) {
            f[i] = g[i - 1] + cnt[i] * i;
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[m], g[m]);
    }
};