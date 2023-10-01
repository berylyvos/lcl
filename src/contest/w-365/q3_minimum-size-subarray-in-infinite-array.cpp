#include <vector>
using namespace std;
// https://leetcode.cn/problems/minimum-size-subarray-in-infinite-array/

//      [ |...| ] 
//      [  |..][..|  ]
//      [  |..][...]...[...][..| ]
// target / sum * n + target % sum 
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long sum = 0;
        for (int& x: nums) sum += x;
        int res = 1e6, n = nums.size();
        int t = target % sum, m = target / sum * n;
        for (int i = 0, j = 0, s = 0; i < n * 2; ++i) {
            s += nums[i % n];
            while (s > t) s -= nums[j++ % n];
            if (s == t) res = min(res, i - j + 1);
        }
        return res == 1e6 ? -1 : res + m;
    }
};