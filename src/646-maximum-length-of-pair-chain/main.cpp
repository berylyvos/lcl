#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.cn/problems/maximum-length-of-pair-chain/

// greedy: O(nlog(n))
// similar to [LC.435] https://leetcode.cn/problems/non-overlapping-intervals/
class Solution3 {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [&](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        int r = -1e5, res = 0;
        for (auto &p: pairs)
            if (p[0] > r) r = p[1], ++res;
        
        return res;
    }
};

// greedy + binary search: O(nlog(n))
// similar to [LC.300] https://leetcode.cn/problems/longest-increasing-subsequence/
class Solution2 {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> q;
        for (auto& p: pairs) {
            if (q.empty() || p[0] > q.back()) q.push_back(p[1]);
            else {
                int l = 0, r = q.size() - 1;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (q[mid] >= p[0]) r = mid;
                    else l = mid + 1;
                }
                q[r] = min(q[r], p[1]);
            }
        }
        return q.size();
    }
};

// DP: O(n^2)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());

        int n = pairs.size();
        vector<int> f(n, 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (pairs[j][1] < pairs[i][0])
                    f[i] = max(f[i], f[j] + 1);
        
        return f[n - 1];
    }
};