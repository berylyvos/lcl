#include <vector>
using namespace std;
// https://leetcode.cn/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        res[0] = 1;
        // prefix product
        for (int i = 1; i < n; ++i) res[i] = nums[i - 1] * res[i - 1];

        for (int i = n - 1, s = 1; i >= 0; --i) {
            // res[i] = prefix product * suffix product
            res[i] *= s;
            s *= nums[i];
        }

        return res;
    }
};