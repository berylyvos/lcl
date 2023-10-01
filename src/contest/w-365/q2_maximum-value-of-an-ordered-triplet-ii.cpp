#include <vector>
using namespace std;
// https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-ii/
// maximum of (nums[i] - nums[j]) * nums[k]s

class Solution2 {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0;
        int n = nums.size(), a = nums[0], b = 0;
        for (int i = 1; i < n; ++i) {
            res = max(res, 1ll * b * nums[i]);
            b = max(b, a - nums[i]);
            a = max(a, nums[i]);
        }
        return res;
    }
};

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        vector<int> c(n + 1);
        for (int i = n - 1; ~i; --i) c[i] = max(c[i + 1], nums[i]);
        
        for (int j = 1, a = nums[0]; j < n - 1; ++j) {
            res = max(res, (long long)(a - nums[j]) * c[j + 1]);
            a = max(a, nums[j]);
        }
        return res;
    }
};