#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;
// https://leetcode.cn/problems/beautiful-towers-ii/
// 前后缀分解 + 单调栈
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& h) {
        int n = h.size();
        vector<ll> pre(n + 1);
        stack<int> st;
        st.push(-1);
        ll s = 0;
        for (int i = 0; i < n; ++i) {
            while (st.size() > 1 && h[i] < h[st.top()]) {
                int j = st.top(); st.pop();
                s -= (ll)h[j] * (j - st.top());
            }
            s += (ll)h[i] * (i - st.top()); 
            pre[i + 1] = s;
            st.push(i);
        }

        ll res = pre[n];
        st = stack<int>();
        st.push(n);
        s = 0;
        for (int i = n - 1; ~i; --i) {
            while (st.size() > 1 && h[i] < h[st.top()]) {
                int j = st.top(); st.pop();
                s -= (ll)h[j] * (st.top() - j);
            }
            s += (ll)h[i] * (st.top() - i); 
            res = max(res, pre[i] + s);
            st.push(i);
        }

        return res;
    }
};

int main() {
    vector<int> h{5,3,4,1,1};
    cout << Solution().maximumSumOfHeights(h) << '\n'; // 13 [5,3,3,1,1]
    vector<int> h1{6,5,3,9,2,7};
    cout << Solution().maximumSumOfHeights(h1) << '\n'; // 22 [3,3,3,9,2,2]
    vector<int> h2{3,2,5,5,2,3};
    cout << Solution().maximumSumOfHeights(h2) << '\n'; // 18 [3,2,5,5,2,3]

    vector<int> h3{528947205,446572672,245562434,29067688,230940022,237916991,546243960,898360263,110809423,616740838,141189952,272319413,173945434,944209607,709147298,291516002,697109513,945372506,321357175,271013697,140905315,154122459,745184252,379717676,468969774,302949377,261867781,933328834,791272529,583341139,83259489,304055888,873655860,808520318,194518325,703266873,281331446,927210596,422874036,902047413,774474564,809609201,493545785,415250991,884864225,392444408,610159103,903379193,816412790,591760883,361140449,759810143,588717612,694204370,42665571,517507625,702706955,952884579};
    cout << Solution().maximumSumOfHeights(h3) << '\n'; // 11903251647

    return 0;
}