#include <vector>
#include <unordered_set>
using namespace std;
// https://leetcode.cn/problems/queens-that-can-attack-the-king/

class Solution2 {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        const int n = 8;
        bool st[n][n] = {0};
        for (auto& q: queens) st[q[0]][q[1]] = true;

        vector<vector<int>> res;
        int x = king[0], y = king[1];
        for (int i = -1; i <= 1; ++i)
            for (int j = -1; j <= 1; ++j) 
                if (i || j) {
                    int a = x + i, b = y + j;
                    while (~a && a < n && ~b && b < n) {
                        if (st[a][b]) {
                            res.push_back({a, b});
                            break;
                        }
                        a += i, b += j;
                    }
                }

        return res;
    }
};

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        const int n = 8;
        const int dir[n][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
        unordered_set<int> q;
        for (auto& x: queens) q.insert(x[0] * n + x[1]);

        vector<vector<int>> res;
        int x = king[0], y = king[1];
        for (auto& d: dir) {
            int a = x + d[0], b = y + d[1];
            while (~a && a < n && ~b && b < n) {
                if (q.find(a * n + b) != q.end()) {
                    res.push_back({a, b});
                    break;
                }
                a += d[0], b += d[1];
            }
        }
        return res;
    }
};