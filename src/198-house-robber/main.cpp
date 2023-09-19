#include <iostream>
#include <vector>

using namespace std;

// FSA dp + spatial optimization
class Solution4 {
public:
    int rob(vector<int>& nums) {
        int f = 0, g = 0, f1;
        for (auto& x: nums) {
            f1 = f;
            f = g + x;
            g = max(g, f1);
        }
        return max(f, g);
    }
};

// linear dp + spatial optimization
class Solution3 {
public:
    int rob(vector<int>& nums) {
        int f0 = 0, f1 = 0, f2 = 0;
        for (auto& x: nums) {
            f2 = max(f1, f0 + x);
            f0 = f1;
            f1 = f2;
        }
        return f1;
    }
};

// linear dp
class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        f[0] = 0, f[1] = nums[0];
        for (int i = 2; i <= n; ++i) f[i] = max(f[i - 1], f[i - 2] + nums[i - 1]);
        return f[n];
    }
};

// memorized search: O(n)
class Solution1 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, -1);

        function<int(int)> dfs = [&](int i) {
            if (i < 0) return 0;
            if (~f[i]) return f[i];
            return f[i] = max(dfs(i - 1), dfs(i - 2) + nums[i]);
        };
        return dfs(n - 1);
    }
};

// dfs: O(2^n) TLE
class Solution_TLE {
public:
    int dfs(vector<int>& a, int i) {
        if (i < 0) return 0;
        return max(dfs(a, i - 1), dfs(a, i - 2) + a[i]);
    }

    int rob(vector<int>& nums) {
        return dfs(nums, nums.size() - 1);
    }
};

int main() {
    vector<int> nums{1, 2, 3, 1};
    cout << Solution2().rob(nums) << '\n'; // 4
    return 0;
}