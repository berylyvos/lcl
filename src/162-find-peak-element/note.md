
# 二分

考虑相邻两个元素满足： `a[i] < a[i + 1]`
- 若 `a[i] < a[i + 1] < ... < a[n - 1]`，则右端点 `a[n - 1]` 为峰值 
- 若存在 `k >= i + 1` 满足 `a[k] > a[k + 1]`，则 `a[k]` 为峰值
  
综上，当 `a[i] < a[i + 1]` 时，峰值一定在 `a[i]` 的右侧，同理可得，当 `a[i - 1] > a[i]` 时，峰值一定在 `a[i]` 的左侧。

所以我们可以每次二分中点，通过判断 `a[mid]` 和 `a[mid + 1]` 的大小关系，可以判断左右两边哪边一定有峰值，从而可以将检索区间缩小一半。

```c++
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[mid + 1]) l = mid + 1;
            else r = mid;
        }
        return r;
    }
};
```