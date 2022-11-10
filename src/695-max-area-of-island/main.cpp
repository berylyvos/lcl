#include <cstdio>
#include <vector>

using namespace std;

// DFS：每个点只遍历一次 O(nm)
class Solution {
public:
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
    // 返回当前连通块的面积
    int dfs(int x, int y, vector<vector<int>>& g) {
        g[x][y] = 0;
        int cnt = 1;
        for (int i = 0; i < 4; ++ i) {
            int a = dx[i] + x, b = dy[i] + y;
            if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == 0) continue;
            cnt += dfs(a, b, g);
        }
        return cnt;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < m; ++ j)
                if (grid[i][j] == 1)
                    res = max(res, dfs(i, j, grid));
        return res;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    printf("%d\n", Solution().maxAreaOfIsland(grid)); // 6
    return 0;
}