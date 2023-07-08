#include <stack>
using namespace std;

// https://leetcode.cn/problems/online-stock-span/

class StockSpanner {
public:
    StockSpanner() {
        st.emplace(INT_MAX, -1);
    }
    
    int next(int price) {
        while (price >= st.top().first) st.pop();
        int res = idx - st.top().second;
        st.emplace(price, idx++);
        return res;
    }

private:
    stack<pair<int, int>> st;
    int idx{0};
};