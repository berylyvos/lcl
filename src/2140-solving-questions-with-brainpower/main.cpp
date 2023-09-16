#include <vector>
using namespace std;
// https://leetcode.cn/problems/solving-questions-with-brainpower/

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> f(n + 1);
        for (int i = n - 1; ~i; --i) {
            int j = min(n, i + 1 + questions[i][1]);
            f[i] = max(f[i + 1], questions[i][0] + f[j]);
        }
        return f[0];
    }
};