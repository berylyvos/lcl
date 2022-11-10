#include <cstdio>
#include <vector>

using namespace std;

// 树状数组
class NumArray {
private:
    vector<int> tr, nums_;
    int n;
    
    int lowbit(int &x) { return x & -x; }
    
    void add(int x, int c) {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }
    
    int query(int x) {
        int res = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) res += tr[i];
        return res;
    }
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tr.resize(n + 1);
        nums_ = nums;
        for (int i = 0; i < n; ++ i) add(i + 1, nums[i]);
    }
    
    void update(int index, int val) {
        add(index + 1, val - nums_[index]);
        nums_[index] = val;
    }
    
    int sumRange(int left, int right) {
        return query(right + 1) - query(left + 1 - 1);
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