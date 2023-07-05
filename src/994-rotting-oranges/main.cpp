#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// https://leetcode.cn/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dx{0, 1, 0, -1}, dy{-1, 0, 1, 0};
        queue<tuple<int, int, int>> q;
        int n = grid.size(), m = grid[0].size();
        int fresh = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 1) ++fresh;
                else if (grid[i][j] == 2) q.emplace(i, j, 0);;
        if (fresh == 0) return 0;
        
        while (!q.empty()) {
            auto [x, y, t] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == 1) {
                    if (--fresh == 0) return t + 1;
                    grid[a][b] = 2;
                    q.emplace(a, b, t + 1);
                }
            }
        }
        
        return -1;
    }
};

int main() {
    vector<vector<int>> g{{1},{2}};
    cout << Solution().orangesRotting(g) << '\n';
}