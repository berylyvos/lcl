#include <vector>
#include <unordered_map>
using namespace std;
// https://leetcode.cn/problems/maximum-sum-of-almost-unique-subarray/

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long res = 0, s = 0;
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (int i = 0, j = 0, t = 0; i < n; ++i) {
            if (cnt[nums[i]]++ == 0) ++t;
            s += nums[i];
            if (i - j >= k) {
                if (--cnt[nums[j]] == 0) --t;
                s -= nums[j++];
            }
            if (i - j + 1 == k && t >= m) res = max(res, s);
        }
        return res;
    }
};