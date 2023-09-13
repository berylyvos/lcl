#include <iostream>
#include <vector>
using namespace std;

// greedy + STL: O(nlog(n))
class Solution3 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> q;
        for (auto &x: nums) {
            auto it = lower_bound(q.begin(), q.end(), x);
            if (it == q.end()) q.push_back(x);
            else *it = x;
        }
        return q.size();
    }
};

// greedy: O(nlog(n))
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        // q[k]: the min element of (k+1)-length increasing subsequence
        // thus, the longest IS is q.size
        vector<int> q;
        for (auto &x: nums) {
            if (q.empty() || x > q.back()) q.push_back(x);
            else {
                // binary search to insert x
                int l = 0, r = q.size() - 1;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (q[mid] >= x) r = mid;
                    else l = mid + 1;
                }
                q[r] = x; // q[r] >= x, replace it with x to make q[r] the minimum
            }
        }

        return q.size();
    }
};

// DP: O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1); // f[i]: LIS of nums[i] as tail
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i])
                    f[i] = max(f[i], f[j] + 1);

        return *max_element(f.begin(), f.end());
    }
};

int main() {
    vector<int> nums{10,9,2,5,3,7,101,18};
    cout << Solution().lengthOfLIS(nums) << '\n'
        << Solution2().lengthOfLIS(nums) << '\n'; // [2,3,7,101]，4 
}