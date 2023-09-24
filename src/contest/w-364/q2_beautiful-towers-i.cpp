#include <vector>
using namespace std;
// https://leetcode.cn/problems/beautiful-towers-i/

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& h) {
        long long res = 0;
        int n = h.size();

        for (int i = 0; i < n; ++i) {
            long long s = h[i];
            for (int j = i - 1, u = h[i]; ~j; --j) {
                u = min(u, h[j]);
                s += u;
            }
            for (int j = i + 1, u = h[i]; j < n; ++j) {
                u = min(u, h[j]);
                s += u;
            }
            res = max(res, s);
        }
        return res;
    }
};