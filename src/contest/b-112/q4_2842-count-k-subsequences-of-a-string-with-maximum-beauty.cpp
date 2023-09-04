#include <string>
#include <vector>
using namespace std;
// https://leetcode.cn/problems/count-k-subsequences-of-a-string-with-maximum-beauty/

using ll = long long;
const int MOD = 1e9 + 7;
const int N = 26;

class Solution {
public:
    int C(int a, int b) {
        int res = 1;
        for (int i = a, j = 1; j <= b; --i, ++j) res = res * i / j;
        return res;
    }

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        if (k > N) return 0;
        
        int cnt[N]{0};
        for (auto &c: s) cnt[c - 'a']++;
        sort(cnt, cnt + 26, greater<int>());

        int l = k - 1, r = l;
        while (l && cnt[l] == cnt[l - 1]) --l;
        while (r + 1 < N && cnt[r] == cnt[r + 1]) ++r;

        ll res = 1;
        for (int i = 0; i < l; ++i) {
            res = res * cnt[i] % MOD;
        }

        return res * C(r - l + 1, k - l) % MOD;
    }
};