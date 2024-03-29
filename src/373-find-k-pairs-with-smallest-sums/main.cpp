#include <vector>
#include <queue>
using namespace std;
// https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/

// multi-way-merge:  O(k * log(min(n, k)))
class Solution {
public:
    using elem = tuple<int, int, int>;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        res.reserve(k);
        priority_queue<elem, vector<elem>, greater<elem>> q;

        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < min(n, k); ++i) q.emplace(nums1[i] + nums2[0], i, 0);

        while (k-- && q.size()) {
            auto [_, i, j] = q.top(); q.pop();
            res.push_back({nums1[i], nums2[j]});
            if (++j < m) q.emplace(nums1[i] + nums2[j], i, j);
        }

        return res;
    }
};