#include <vector>
using namespace std;
// https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

//DFS
class Solution2 {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n);
        function<int(int)> dfs = [&](const int& u) {
            int s = 1;
            vis[u] = true;
            for (const int& j: g[u]) if (!vis[j]) s += dfs(j);
            return s;
        };

        long long res = 0;
        for (int i = 0; i < n; ++i) if (!vis[i]) {
            int s = dfs(i);
            res += 1ll * s * (n - s);
        }
        return res / 2;
    }
};

// Union find
class Solution1 {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> p(n), cnt(n, 1);
        for (int i = 0; i < n; ++i) p[i] = i;
        function<int(int)> find = [&](int x) {
            if (x != p[x]) p[x] = find(p[x]);
            return p[x];
        };
        auto merge = [&](int a, int b) {
            a = find(a), b = find(b);
            if (a != b) {
                p[b] = a;
                cnt[a] += cnt[b];
            }
        };

        for (auto& e: edges) merge(e[0], e[1]);

        long long res = 0;
        for (int i = 0; i < n; ++i) res += n - cnt[find(i)];        
        return res / 2;
    }
};