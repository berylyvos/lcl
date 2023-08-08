#include <vector>
#include <numeric> // iota
using namespace std;

// https://leetcode.cn/problems/find-the-safest-path-in-a-grid/

// BFS + UnionFind
class Solution {
    using pii = pair<int, int>;
    const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return 0;
        vector<vector<int>> d(n, vector<int>(n, -1));
        vector<pii> q;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) {
                    d[i][j] = 0;
                    q.emplace_back(i, j);
                }

        // 多源bfs
        vector<vector<pii>> levels {q};
        while (q.size()) {
            vector<pii> nq;
            int sz = levels.size();
            for (auto &[x, y]: q) {
                for (int i = 0; i < 4; ++i) {
                    int a = x + dx[i], b = y + dy[i];
                    if (a < 0 || a >= n || b < 0 || b >= n || d[a][b] >= 0) continue;
                    d[a][b] = sz;
                    nq.emplace_back(a, b);
                }
            }
            levels.emplace_back(nq);
            q = move(nq);
        }
        
        // 并查集
        vector<int> p(n * n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            if (x != p[x]) return p[x] = find(p[x]);
            return p[x];
        };

        // 倒序枚举答案
        for (int ans = levels.size() - 2; ~ans; --ans) {
            for (auto &[x, y]: levels[ans]) {
                for (int k = 0; k < 4; ++k) {
                    int a = x + dx[k], b = y + dy[k];
                    if (a < 0 || a >= n || b < 0 || b >= n || d[a][b] < d[x][y]) continue;
                    int p1 = find(x * n + y), p2 = find(a * n + b);
                    if (p1 != p2) p[p2] = p1;
                }
            }
            if (find(0) == find(n * n - 1)) return ans;
        }

        return 0;
    }
};