class Solution {
public:
    int mySqrt(int x) {
        // find the min k satisfy k^2 <= x
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + r + 1L) >> 1;
            if (mid <= x / mid) l = mid;
            else r = mid - 1;
        }
        return r;
    }
};