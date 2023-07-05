#include <vector>
#include <queue>
using namespace std;

// https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> dx{0, 1, 0, -1}, dy{-1, 0, 1, 0};
        queue<tuple<int, int, int>> q;
        q.emplace(entrance[0], entrance[1], 0);
        int n = maze.size(), m = maze[0].size();
        maze[entrance[0]][entrance[1]] = '+';
        
        while (!q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < n && b >= 0 && b < m && maze[a][b] == '.') {
                    if (a == 0 || a == n - 1 || b == 0 || b == m - 1) return d + 1;
                    maze[a][b] = '+';
                    q.emplace(a, b, d + 1);
                }
            }
        }
        
        return -1;
    }
};