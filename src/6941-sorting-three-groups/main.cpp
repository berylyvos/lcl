#include <vector>
using namespace std;

// https://leetcode.cn/problems/sorting-three-groups/description/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), res = n;
        // 枚举 i, j 作为第一、二段的长度
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j + i <= n; ++j) {
                int cnt = 0;
                // 遍历原数组，若当前元素是否与所在组的编号不匹配，操作数加一
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