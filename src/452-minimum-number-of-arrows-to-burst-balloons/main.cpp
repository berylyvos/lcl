#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int res = 1, r = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > r) {
                ++res;
                r = points[i][1];
            }
        }

        return res;
    }
};