#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;
// https://leetcode.cn/problems/maximum-elegance-of-a-k-length-subsequence/

// regret greedy
class Solution {
    using ll = long long;
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n = items.size();
        // 利润降序
        sort(items.begin(), items.end(), [](const auto& a, const auto& b){
            return a[0] > b[0];
        });

        ll ans = 0, s = 0;
        unordered_set<int> category;
        stack<int> duplicate; // 重复类别的利润
        for (int i = 0; i < n; ++i) {
            int p = items[i][0], c = items[i][1];
            if (i < k) {
                s += p;
                if (!category.insert(c).second) duplicate.push(p);
            } else if (duplicate.size() && category.insert(c).second) {
                s += p - duplicate.top();
                duplicate.pop();
            }
            ans = max(ans, s + (ll)category.size() * (ll)category.size());
        }

        return ans;
    }
};