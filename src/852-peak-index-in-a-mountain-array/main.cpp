#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

// 山脉数组
// 存在 i（0 < i < arr.length - 1）使得：
// arr[0] < arr[1] < ... arr[i-1] < arr[i]
// arr[i] > arr[i+1] > ... > arr[arr.length - 1]
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        assert(arr.size() >= 3);
        int l = 1, r = arr.size() - 2;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (arr[mid - 1] < arr[mid]) l = mid;
            else r = mid - 1;
        }
        return r;
    }
};

int main()
{
    vector<int> arr = {0, 4, 5, -1};
    printf("%d\n", Solution().peakIndexInMountainArray(arr)); // 2

    return 0;
}