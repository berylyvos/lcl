#include <vector>
#include <unordered_map>
using namespace std;

// https://leetcode.cn/problems/binary-trees-with-factors/

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        unordered_map<int, int> idx;
        for (int i = 0; i < n; ++i) idx[arr[i]] = i;

        vector<int> f(n, 1);
        int res = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j)
                if (arr[i] % arr[j] == 0 &&
                    idx.find(arr[i] / arr[j]) != idx.end()) {
                    int k = idx[arr[i] / arr[j]];
                    f[i] = (f[i] + (long long)f[j] * f[k]) % mod;
                }
            res = (res + f[i]) % mod;
        }

        return res;
    }
};