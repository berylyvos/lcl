#include <vector>
using namespace std;
// https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/

// 3 Sliding Windows
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        int s1 = 0, mx1 = 0, m1 = 0;
        int s2 = 0, mx2 = 0, m12_1 = 0, m12_2 = 0;
        int s3 = 0, mx = 0;
        // [0,  k  - 1]
        // [k,  2k - 1]
        // [2k, 3k - 1]
        for (int i = k * 2; i < n; ++i) {
            s1 += nums[i - k * 2];
            s2 += nums[i - k];
            s3 += nums[i];
            
            if (i - k * 3 + 1 >= 0) {

                if (s1 > mx1) {
                    mx1 = s1;
                    m1 = i - k * 3 + 1;
                }

                if (mx1 + s2 > mx2) {
                    mx2 = mx1 + s2;
                    m12_1 = m1;
                    m12_2 = i - k * 2 + 1;
                }

                if (mx2 + s3 > mx) {
                    mx = mx2 + s3;
                    res = {m12_1, m12_2, i - k + 1};
                }

                s1 -= nums[i - k * 3 + 1];
                s2 -= nums[i - k * 2 + 1];
                s3 -= nums[i - k + 1];
            }
        }
        return res;
    }
};