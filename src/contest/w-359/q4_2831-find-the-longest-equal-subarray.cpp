#include <vector>
using namespace std;
// https://leetcode.cn/problems/find-the-longest-equal-subarray/

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> p(n + 1);
        for (int i = 0; i < n; ++i) p[nums[i]].push_back(i);

        int res = 0;
        for (int u = 1; u <= n; ++u) {
            auto& q = p[u];
            for (int i = 0, j = 0; i < q.size(); ++i) {
                while (q[i] - q[j] - (i - j) > k) ++j;
                res = max(res, i - j + 1);
            }
        }

        return res;
    }
};