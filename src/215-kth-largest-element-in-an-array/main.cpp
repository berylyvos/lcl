#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/kth-largest-element-in-an-array/

// [Quick Select]: O(n)
class Solution {
public:
    int qselect(vector<int>& a, int l, int r, int k) {
        if (l >= r) return a[k];
        int i = l - 1, j = r + 1, x = a[rand() % (r - l + 1) + l];
        while (i < j) {
            while (a[++i] > x);
            while (a[--j] < x);
            if (i < j) swap(a[i], a[j]);
        }
        if (k <= j) return qselect(a, l, j, k);
        else return qselect(a, j + 1, r, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return qselect(nums, 0, nums.size() - 1, k - 1);
    }
};

// [Max Heap]: O(nlogn)
class Solution2 {
public:
    int sz;
    
    void down(vector<int>& heap, int u) {
        int t = u, i = 2 * u + 1, j = i + 1;
        if (i < sz && heap[i] > heap[t]) t = i;
        if (j < sz && heap[j] > heap[t]) t = j;
        if (t != u) {
            swap(heap[u], heap[t]);
            down(heap, t);
        }
    }
    
    void initHeap(vector<int>& nums) {
        for (int i = sz / 2 - 1; i >= 0; --i) down(nums, i);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        sz = nums.size();
        initHeap(nums);
        while (--k) {
            nums[0] = nums[--sz];
            down(nums, 0);
        }
        return nums[0];
    }
};

int main() {
    vector<int> nums{3, 1, 0, 5, 2, 4};
    cout << Solution().findKthLargest(nums, 2) << '\n'; // 4
}