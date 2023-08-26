#include <vector>
using namespace std;
// https://leetcode.cn/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const auto& a, const auto& b){
            return a[0] < b[0];
        });
        int n = intervals.size();
        vector<vector<int>> res;
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] <= right) right = max(right, intervals[i][1]);
            else {
                res.emplace_back(vector<int>{left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        res.emplace_back(vector<int>{left, right});
        return res;
    }
};