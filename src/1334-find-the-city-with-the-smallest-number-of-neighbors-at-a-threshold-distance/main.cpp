#include <vector>
using namespace std;
// https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

// Floyd O(n^3)
class Solution2 {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> d(n, vector<int>(n, 1e8));
        for (int i = 0; i < n; ++i) d[i][i] = 0;
        for (auto& e: edges) {
            int a = e[0], b = e[1];
            d[a][b] = d[b][a] = e[2];
        }

        // floyd
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        int id = -1, minCnt = n;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) if (d[i][j] <= distanceThreshold) {
                ++cnt;
            }
            if (cnt <= minCnt) {
                minCnt = cnt;
                id = i;
            }
        }

        return id;
    }
};

// Dijkstra for every node. O(n^3)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> g(n, vector<int>(n, 1e8));
        vector<vector<int>> d(n, vector<int>(n, 1e8));
        vector<vector<bool>> st(n, vector<bool>(n, false));
        for (auto& e: edges) {
            int a = e[0], b = e[1];
            g[a][b] = g[b][a] = e[2];
        }

        for (int i = 0; i < n; ++i) {
            d[i][i] = 0;
            
            // dijkstra 求当前点 i 到其他所有点的最短距离 d[i][j]
            for (int _ = 0; _ < n; ++_) {
                int t = -1;
                for (int j = 0; j < n; ++j)
                    if (!st[i][j] && (t == -1 || d[i][j] < d[i][t])) t = j;
                st[i][t] = true;
                
                for (int j = 0; j < n; ++j)
                    d[i][j] = min(d[i][j], d[i][t] + g[t][j]);
            }
        }

        int id = -1, minCnt = n;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) if (d[i][j] <= distanceThreshold) {
                ++cnt;
            }
            if (cnt <= minCnt) {
                minCnt = cnt;
                id = i;
            }
        }

        return id;
    }
};