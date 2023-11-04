#include <vector>
#include <unordered_set>
using namespace std;
// https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/

// Using hash map similar to [two-um]
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        if (mx == 0) return 0;
        
        int high_bit = -1;
        // int high_bit = mx ? 31 - __builtin_clz(mx) : -1;
        for (int i = 30; ~i; --i) if (mx >> i & 1) {
            high_bit = i;
            break;
        }

        int res = 0, mask = 0;
        unordered_set<int> s;
        for (int i = high_bit; ~i; --i) {
            s.clear();
            mask |= 1 << i;
            int t = res | (1 << i);
            for (int x: nums) {
                x &= mask;
                if (s.find(t ^ x) != s.end()) {
                    res = t;
                    break;
                }
                s.insert(x);
            }
        }
        
        return res;
    }
};

// Trie
class Solution1 {
public:
    static const int N = 200000 * 31 + 1;
    int son[N][2];
    int idx = 0;

    int query(const int& x) {
        int p = 0, res = 0;
        for (int i = 30; ~i; --i) {
            int u = x >> i & 1;
            if (son[p][!u]) {
                p = son[p][!u];
                res <<= 1;
                res |= !u;
            } else {
                p = son[p][u];
                res <<= 1;
                res |= u;
            }
        }
        return res ^ x;
    }

    void insert(const int& x) {
        int p = 0;
        for (int i = 30; ~i; --i) {
            int u = x >> i & 1;
            if (!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
    }

    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        for (int &x: nums) {
            res = max(res, query(x));
            insert(x);
        }
        return res;
    }
};