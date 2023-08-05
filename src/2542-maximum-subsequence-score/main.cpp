#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        // sort idx by nums2 desc
        vector<int> idx(n);
        for (int i = 0; i < n; ++i) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](const int& i, const int& j){
            return nums2[i] > nums2[j];
        });

        long long res = 0, s = 0;
        // min heap to maintain k-max in nums1
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i: idx) {
            int x = nums1[i], y = nums2[i];
            
            while (q.size() >= k) {
                s -= q.top();
                q.pop();
            }
            q.push(x);
            s += x;

            if (q.size() == k) {
                res = max(res, s * y);
            }
        }

        return res;
    }
};