#include <vector>
using namespace std;

// https://leetcode.cn/problems/longest-arithmetic-subsequence/

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        const int offset = 500;
        int n = nums.size(), res = 0;
        vector<vector<int>> f(n, vector<int>(2 * offset + 1, 1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j) {
                int k = nums[i] - nums[j] + offset;
                f[i][k] = max(f[i][k], f[j][k] + 1);
                res = max(res, f[i][k]);
            }
        
        return res;
    }
};