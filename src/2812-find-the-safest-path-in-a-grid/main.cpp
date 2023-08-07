#include <vector>
#include <queue>
using namespace std;

// https://leetcode.cn/problems/find-the-safest-path-in-a-grid/

// BFS + UnionFind
class Solution {
    const int INF = 1e9;
    const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return 0;
        vector<vector<int>> d(n, vector<int>(n, INF));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) {
                    d[i][j] = 0;
                    q.emplace(i, j);
                }

        while (q.size()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= n || d[a][b] < INF) continue;
                d[a][b] = d[x][y] + 1;
                q.emplace(a, b);
            }
        }

        int p[n * n];
        for (int i = 0; i < n * n; ++i) p[i] = i;

        vector<vector<int>> g(2 * n + 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g[d[i][j]].push_back(i * n + j);
        
        function<int(int)> find = [&](int x) {
            if (x != p[x]) return p[x] = find(p[x]);
            return p[x];
        };

        for (int i = g.size() - 1; ~i; --i) {
            for (int j = 0; j < g[i].size(); ++j) {
                int x = g[i][j] / n, y = g[i][j] % n;
                for (int k = 0; k < 4; ++k) {
                    int a = x + dx[k], b = y + dy[k];
                    if (a < 0 || a >= n || b < 0 || b >= n || d[a][b] < d[x][y]) continue;
                    int pa = find(x * n + y), pb = find(a * n + b);
                    if (pa != pb) p[pb] = pa;
                }
            }
            if (find(0) == find(n * n - 1)) return i;
        }

        return 0;
    }
};