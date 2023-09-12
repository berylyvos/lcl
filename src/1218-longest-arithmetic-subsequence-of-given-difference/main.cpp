#include <vector>
#include <unordered_map>
using namespace std;

// https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> f;
        int res = 0;
        for (auto &x: arr) {
            f[x] = f[x - difference] + 1;
            res = max(res, f[x]);
        }
        return res;
    }
};