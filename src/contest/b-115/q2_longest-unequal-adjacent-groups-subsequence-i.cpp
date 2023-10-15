#include <vector>
using namespace std;
// https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-i/

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> res;
        for (int i = 0, pre = -1; i < n; ++i)
            if (groups[i] != pre) {
                res.push_back(words[i]);
                pre = groups[i];
            }
        
        return res;
    }
};