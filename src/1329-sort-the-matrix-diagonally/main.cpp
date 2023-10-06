#include <vector>
using namespace std;
// https://leetcode.cn/problems/sort-the-matrix-diagonally/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> t;
        // 左对角线 x - y = b;
        for (int b = -(m - 1), x, y; b < n; ++b) {
            t.clear();
            x = b > 0 ? b : 0;
            y = b > 0 ? 0 : -b;
            for (int i = x, j = y; i < n && j < m; ++i, ++j) t.push_back(mat[i][j]);
            sort(t.begin(), t.end());
            for (int i = x, j = y, k = 0; i < n && j < m; ++i, ++j, ++k) mat[i][j] = t[k];
        }
        return mat;
    }
};