#include <vector>
using namespace std;
// https://leetcode.cn/problems/split-array-into-maximum-number-of-subarrays/

// Tip: 按位与越来越小，按位或越或越大
class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        const int M = -1;
        int s = M,res = 0;
        for (int& x: nums) {
            s &= x;
            if (!s) {
                ++res;
                s = M;
            }
        }
        return res ? res : 1;
    }
};