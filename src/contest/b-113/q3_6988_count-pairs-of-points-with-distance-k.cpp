#include <vector>
#include <unordered_map>
using namespace std;
// https://leetcode.cn/problems/count-pairs-of-points-with-distance-k/

// a ^ b = k  =>  b = a ^ k 
// (I dont know this shit, man. Fuck!
class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        const long long N = 1e6;
        int res = 0;
        unordered_map<long long, int> cnt;
        for (auto& c: coordinates) {
            for (int i = 0; i <= k; ++i) {
                int a = i ^ c[0], b = (k - i) ^ c[1];
                res += cnt[a * N + b];
            }
            ++cnt[c[0] * N + c[1]];
        }
        return res; 
    }
};