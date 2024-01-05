#include <vector>
#include <stack>
using namespace std;
// https://leetcode.cn/problems/number-of-visible-people-in-a-queue

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n);
        stack<int> st;
        
        for (int i = n - 1; ~i; --i) {
            while (st.size() && heights[st.top()] < heights[i]) {
                st.pop();
                res[i]++;
            }
            res[i] += !st.empty();
            st.push(i);
        }

        return res;
    }
};