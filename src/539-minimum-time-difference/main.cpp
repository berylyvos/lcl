#include <string>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/minimum-time-difference/

class Solution {
public:
    int getMinutes(const string &t) {
        return ((t[0] - '0') * 10 + (t[1] - '0')) * 60 + (t[3] - '0') * 10 + (t[4] - '0');
    }

    int findMinDifference(vector<string>& timePoints) {
        const int N = 24 * 60;
        int res = 1e8, n = timePoints.size();
        if (n > N) return 0;

        vector<int> t(n);
        for (int i = 0; i < n; ++i) t[i] = getMinutes(timePoints[i]);
        sort(t.begin(), t.end());
        for (int i = 1; i < n; ++i) res = min(res, t[i] - t[i - 1]);
        return min(res, N - t[n - 1] + t[0]);
    }
};