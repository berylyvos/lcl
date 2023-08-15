#include <string>
#include <vector>
#include <numeric>
using namespace std;

// https://leetcode.cn/problems/find-and-replace-in-string/

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return indices[i] > indices[j];
        });
        // 从后往前替换，这样s的index不会发生改变
        for (int i = 0; i < n; ++i) {
            int k = idx[i];
            int j = indices[k], sz = sources[k].size();
            if (s.substr(j, sz) == sources[k]) {
                s = s.substr(0, j) + targets[k] + s.substr(j + sz);
            }
        }
        
        return s;
    }
};