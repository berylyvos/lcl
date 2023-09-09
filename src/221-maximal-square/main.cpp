#include <vector>
using namespace std;

// https://leetcode.cn/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> f(n, vector<int>(m));

        int k = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) f[i][j] = 1;
                else f[i][j] = min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;
                k = max(k, f[i][j]);
            }
        
        return k * k;
    }
};