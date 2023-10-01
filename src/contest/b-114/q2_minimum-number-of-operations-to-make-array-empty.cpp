#include <vector>
#include <unordered_map>
using namespace std;
// https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-empty/

// 如果 c == 1，无法操作，返回 −1。
// 如果 c 是 3 的倍数，那么可以用 c / 3 次操作删除。
//    如果 c % 3 为 1，那么 c = (c − 4) + 4，其中 c − 4 是 3 的倍数，剩余的 4 可以用两次操作完成。
//    如果 c % 3 为 2，那么 c = (c − 2) + 2，其中 c − 2 是 3 的倍数，剩余的 2 可以用一次操作完成。
// 总之，都需要 上取整[c / 3] = 下取整[c + 3 - 1 / 3]
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int& x: nums) cnt[x]++;
        int res = 0;
        for (auto& [_, c]: cnt)
            if (c == 1) return -1;
            else res += (c + 3 - 1) / 3;
        return res;
    }
};