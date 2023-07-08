#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.cn/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });

        int res = 0, r = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < r) ++res;
            else r = intervals[i][1];
        }

        return res;
    }
};