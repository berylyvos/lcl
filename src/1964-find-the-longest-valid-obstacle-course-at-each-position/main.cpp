#include <vector>
using namespace std;
// https://leetcode.cn/problems/find-the-longest-valid-obstacle-course-at-each-position/

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> res(n), f;
        for (int i = 0; i < n; ++i) {
            int x = obstacles[i];
            if (f.empty() || f.back() <= x) {
                f.push_back(x);
                res[i] = f.size();
            } else {
                // int l = 0, r = f.size() - 1;
                // while (l < r) {
                //     int mid = (l + r) >> 1;
                //     if (f[mid] > x) r = mid;
                //     else l = mid + 1;
                // }
                int r = upper_bound(f.begin(), f.end(), x) - f.begin();
                f[r] = x;
                res[i] = r + 1;
            }
        } 
        return res;
    }
};