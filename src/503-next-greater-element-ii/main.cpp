#include <stack>
#include "headers/vector.h"

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < 2 * n - 1; ++ i) {
            while (st.size() && nums[i % n] > nums[st.top()]) {
                res[st.top()] = nums[i % n];
                st.pop();
            }
            if (i < n) st.push(i); // 后半段不需要重复入栈
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {4, 1, 3, 2};
    print_vec(Solution().nextGreaterElements(nums)); // -1, 3, 4, 4

    return 0;
}