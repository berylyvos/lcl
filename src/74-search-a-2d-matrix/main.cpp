#include <vector>
using namespace std;

// 1   3   5   7
// 10  11  16  20
// 23  30  34  50

// #1 binary search: O(log(n * m))
class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1;
        
        while (l < r) {
            int mid = (l + r) >> 1;
            if (matrix[mid / m][mid % m] < target) l = mid + 1;
            else r = mid;
        }

        return matrix[r / m][r % m] == target;
    }
};

// #2 Z-search: O(n + m)
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            int cur = matrix[i][j];
            if (cur < target) {
                ++i;
            } else if (cur > target) {
                --j;
            } else {
                return true;
            }
        }
        return false;
    }
};