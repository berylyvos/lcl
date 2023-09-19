#include <vector>
using namespace std;
// https://leetcode.cn/problems/magnetic-force-between-two-balls/ 
// 二分求最大的最小值
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();

        auto check = [&](const int& d) {
            int cnt = 0;
            for (int i = 1, j = 0; i < n; ++i)
                if (position[i] - position[j] >= d) {
                    ++cnt;
                    j = i;
                }
            return cnt >= m - 1;
        };

        int l = 1, r = position[n - 1] - position[0];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return r;
    }
};