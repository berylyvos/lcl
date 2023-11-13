#include <cstdio>
#include <vector>
using namespace std;
// https://leetcode.cn/problems/range-sum-query-mutable

// 树状数组
class NumArray {
public:
    int n;
    vector<int> t, arr;

    int lowbit(int x) { return x & (-x); }

    void add(int i, int c) {
        for (; i <= n; i += lowbit(i)) t[i] += c;
    }

    int preSum(int i) {
        int s = 0;
        for (; i; i -= lowbit(i)) s += t[i];
        return s;
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        t.resize(n + 1);
        arr = nums;

        for (int i = 1; i <= n; ++i) {
            t[i] += nums[i - 1];
            if (i + lowbit(i) <= n) t[i + lowbit(i)] += t[i];
        }
    }
    
    void update(int index, int val) {
        add(index + 1, val - arr[index]);
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        return preSum(right + 1) - preSum(left);
    }
};

int main()
{
    vector<int> nums {1, 3, 5};
    NumArray na = NumArray(nums);
    printf("%d\n", na.sumRange(0, 2)); // 1 + 3 + 5 = 9;
    na.update(1, -2);
    printf("%d\n", na.sumRange(0, 2)); // 1 + -2 + 5 = 4;

    return 0;
}