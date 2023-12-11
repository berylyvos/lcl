#include <vector>
#include <queue>
using namespace std;
// https://leetcode.cn/problems/path-with-minimum-effort/

class Solution {
public:
    const int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
    int n, m;

    bool check(vector<vector<int>>& heights, const int& d) {
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        vector<bool> st(n * m, false);
        st[0] = true;
        while (q.size()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int a = x + dx[i], b = y + dy[i];
                if (~a && a < n && ~b && b < m && !st[a * m + b]
                    && abs(heights[a][b] - heights[x][y]) <= d) {
                    q.emplace(a, b);
                    st[a * m + b] = true;
                }
            }
        }
        return st[n * m - 1];
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();

        int l = 0, r = 1e6 - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(heights, mid)) r = mid;
            else l = mid + 1;
        }

        return r;
    }
};