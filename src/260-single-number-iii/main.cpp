#include <vector>
using namespace std;
// https://leetcode.cn/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // a ^ b
        int ab = 0;
        for (int& x: nums) ab ^= x;
        
        // find a bit position k where a ^ b = 1 
        int k;
        for (int i = 0; i < 32; ++i)
            if (ab >> i & 1) {
                k = i;
                break;
            }
        
        int a = 0, b = 0;
        for (int& x: nums)
            if (x >> k & 1) a ^= x;
            else b ^= x;

        return {a, b}; 
    }
};