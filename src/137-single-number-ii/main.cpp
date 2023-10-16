#include <vector>
using namespace std;
// https://leetcode.cn/problems/single-number-ii/

// [6, 6, 3, 6]
//  1 1 0
//  1 1 0
//  0 1 1
//  1 1 0
// -------
//  3 1 1
//%3------
//  0 1 1 == 3
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int &x: nums) cnt += x >> i & 1;
            res |= (cnt % 3) ? 1 << i : 0;
        }
        return res;
    }
};