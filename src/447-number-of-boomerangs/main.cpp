#include <vector>
#include <unordered_map>
using namespace std;
// https://leetcode.cn/problems/number-of-boomerangs

class Solution {
public:
    int dis(vector<int>& a, vector<int>& b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + 
               (a[1] - b[1]) * (a[1] - b[1]);
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0, n = points.size();
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> cnt;
            for (int j = 0; j < n; ++j) if (j != i) {
                cnt[dis(points[i], points[j])] ++;
            }
            for (auto [_, c]: cnt) res += c * (c - 1);
        }
        return res;
    }
};