#include <vector>
using namespace std;
// https://leetcode.cn/problems/minimum-degree-of-a-connected-trio-in-a-graph/description/

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>(n));
        vector<int> d(n);

        for (auto& e: edges) {
            int a = e[0] - 1, b = e[1] - 1;
            g[a][b] = g[b][a] = 1;
            ++d[a], ++d[b];
        }

        int res = 1e9;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (g[i][j])
                    for (int k = j + 1; k < n; ++k)
                        if (g[i][k] && g[j][k])
                            res = min(res, d[i] + d[j] + d[k] - 6);
        
        return res == 1e9 ? -1 : res;
    }
};