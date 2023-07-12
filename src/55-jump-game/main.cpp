#include <vector>
using namespace std;

// https://leetcode.cn/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (i > j) return false;
            j = max(j, i + nums[i]);
        }
        return true;
    }
};

class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        // j 指向 [0, i - 1]中第一个能跳到 i 的位置
        // 如果发现 i 之前所有位置均无法到达 i，则返回 false
        for (int i = 1, j = 0; i < n; ++i) {

            while (j < i && j + nums[j] < i) ++j;

            if (j == i) return false;
        }

        return true;
    }
};