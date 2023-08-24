#include <vector>
using namespace std;

// https://leetcode.cn/problems/count-servers-that-communicate/
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row(n), col(m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j]) {
                    ++row[i];
                    ++col[j];
                }
        
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] && (row[i] > 1 || col[j] > 1)) ++res;
                
        return res;
    }
};