#include <vector>
using namespace std;

// https://leetcode.cn/problems/russian-doll-envelopes/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 先按w升序，当w相同时，按h降序排序
        // 求 h 的最长上升子序列，保证了同一个 w 最多被选一次
        sort(envelopes.begin(), envelopes.end(), [&](const auto& a, const auto& b) {
            return (a[0] != b[0]) ? a[0] < b[0] : a[1] > b[1];
        });
        vector<int> f;
        for (auto &e: envelopes) {
            int x = e[1];
            if (f.empty() || f.back() < x) f.push_back(x);
            else {
                int l = 0, r = f.size() - 1;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (f[mid] >= x) r = mid;
                    else l = mid + 1;
                }
                f[r] = x;
            }
        }
        return f.size();
    }
};