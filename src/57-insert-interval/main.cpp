#include <vector>
using namespace std;
// https://leetcode.cn/problems/insert-interval/

class Solution2 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int a = newInterval[0], b = newInterval[1];
        int i = 0, n = intervals.size();
        // 左侧无重叠
        while (i < n && intervals[i][1] < a) res.push_back(intervals[i++]);

        // 重叠部分
        if (i < n) {
            a = min(a, intervals[i][0]);
            while (i < n && intervals[i][0] <= b) b = max(b, intervals[i++][1]);
        }
        res.push_back({a, b});

        // 右侧无重叠
        while (i < n) res.push_back(intervals[i++]);
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int a = newInterval[0], b = newInterval[1];
        bool placed = false;
        for (auto& cur: intervals) {
            if (b < cur[0]) { // [a, b] [cur] ...
                if (!placed) {
                    res.push_back({a, b});
                    placed = true;
                }
                res.push_back(cur);
            } 
            else if (a > cur[1]) { // ...[cur] [a, b]
                res.push_back(cur);
            }
            else {
                // [a  { } b]
                // { [a  b] }
                // [a {  b] }
                // { [a  } b]
                a = min(a, cur[0]);
                b = max(b, cur[1]);
            } 
        }
        // {...} [a, b]
        if (!placed) res.push_back({a, b});

        return res;
    }
};