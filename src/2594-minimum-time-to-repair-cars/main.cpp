#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

// https://leetcode.cn/problems/minimum-time-to-repair-cars/description/?envType=daily-question&envId=2023-09-07

class Solution {
public:
    long long repairCars(vector<int>& ranks, int n) {
           
        ll l = 1, r = 1ll * ranks[0] * n * n;

        while (l < r) {
            ll t = (l + r) >> 1, cnt = 0;
            for (auto &x: ranks) cnt += sqrt(t / x);
            if (cnt >= n) r = t;
            else l = t + 1;
        }

        return r;
    }
};