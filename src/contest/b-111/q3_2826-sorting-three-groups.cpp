#include <vector>
using namespace std;
// https://leetcode.cn/problems/sorting-three-groups/description/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), res = n;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j + i <= n; ++j) {
                int cnt = 0;
                for (int k = 0, t; k < n; ++k) {
                    if (k < i) t = 1;
                    else if (k < i + j) t = 2;
                    else t = 3;
                    if (t != nums[k]) ++cnt;
                }
                res = min(res, cnt);
            }
        
        return res;
    }
};