#include <vector>
using namespace std;

// https://leetcode.cn/problems/maximum-profit-in-job-scheduling/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> job(n);
        for (int i = 0; i < n; ++i) job[i] = {startTime[i], endTime[i], profit[i]};
        sort(job.begin(), job.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        vector<int> f(n);
        f[0] = job[0][2];
        for (int i = 1; i < n; ++i) {
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (job[mid][1] <= job[i][0]) l = mid;
                else r = mid - 1;
            }
            if (job[r][1] <= job[i][0]) f[i] = max(f[i - 1], f[r] + job[i][2]);
            else f[i] = max(f[i - 1], job[i][2]);
        }
        return f[n - 1];
    }
};