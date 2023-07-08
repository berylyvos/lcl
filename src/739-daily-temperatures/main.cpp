#include <vector>
#include <stack>
using namespace std;

// https://leetcode.cn/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> res(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            while (st.size() && t[i] >= t[st.top()]) st.pop();
            if (st.size()) res[i] = st.top() - i;
            st.push(i);
        }

        return res;
    }
};

class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size(), top = 0;
        vector<int> res(n);
        vector<int> st(n);

        for (int i = 0; i < n; ++i) {
            while (top && t[i] > t[st[top]]) {
                res[st[top]] = i - st[top];
                --top;
            }
            st[++top] = i;
        }

        return res;
    }
};