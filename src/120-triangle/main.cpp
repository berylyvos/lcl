#include <cstdio>
#include <vector>

using namespace std;

#define INT_MAX    0x7fffffff

class Solution {
public:
    // 1. 修改原数组 O(1)空间
    int minimumTotal(vector<vector<int>>& f) {
        for (int i = f.size() - 2; i >= 0; -- i)
            for (int j = 0; j <= i; ++ j)
                f[i][j] += min(f[i + 1][j], f[i + 1][j + 1]);
        return f[0][0];
    }

    // 2. 另开二维数组 O(n^2)空间
    int minimumTotal1(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++ i) f[n - 1][i] = triangle[n - 1][i];
        for (int i = n - 2; i >= 0; -- i)
            for (int j = 0; j <= i; ++ j)
                f[i][j] = min(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j];
        return f[0][0];
    }

    // 3. 滚动数组 O(n)空间
    int minimumTotal2(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n, INT_MAX);
        for (int i = 0; i < n; ++ i) f[i] = triangle[n - 1][i];
        for (int i = n - 2; i >= 0; -- i)
            for (int j = 0; j <= i; ++ j)
                f[j] = min(f[j], f[j + 1]) + triangle[i][j];
        return f[0];
    }
};

int main() {
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}};
    
    printf("%d\n", Solution().minimumTotal2(triangle)); // 2 + 3 + 5 + 1 = 11
    return 0;
}