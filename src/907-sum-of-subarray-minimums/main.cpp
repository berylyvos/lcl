#include <vector>
#include <stack>
using namespace std;
// https://leetcode.cn/problems/sum-of-subarray-minimums/

// mono stack + individual contribution
class Solution {
public:
    const int MOD = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        // CORNER CASE: 为保证答案不重复，当区间中有多个最小值时，取最左边的。
        int n = arr.size(), res = 0;
        vector<int> l(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            // (<= x) [... x
            while (st.size() && arr[i] < arr[st.top()]) st.pop();
            l[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1, r; ~i; --i) {
            // x ...] (< x)
            while (st.size() && arr[i] <= arr[st.top()]) st.pop();
            r = st.size() ? st.top() : n;
            res = (res + 1LL * arr[i] * (i - l[i]) * (r - i)) % MOD;
            st.push(i);
        }
        return res;
    }
};