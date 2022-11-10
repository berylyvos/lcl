#include <unordered_map>
#include <stack>
#include "headers/vector.h"

using namespace std;

// 单调栈，哈希表
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextG;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; -- i) {
            int cur = nums2[i];
            while (st.size() && cur >= st.top()) st.pop();
            nextG[cur] = st.empty() ? -1 : st.top();
            st.push(cur);
        }
        
        vector<int> res(nums1.size());
        for (int i = 0; i < (int)nums1.size(); ++ i) res[i] = nextG[nums1[i]];
        return res;
    }
};

int main()
{
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    print_vec(Solution().nextGreaterElement(nums1, nums2));
    // -1,3,-1
    return 0;
}