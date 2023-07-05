#include <vector>
using namespace std;

// https://leetcode.cn/problems/koko-eating-bananas/

class Solution {
public:
    int getHours(const vector<int>& piles, int k) {
        int s = 0;
        for (auto p: piles) s += (p + k - 1) / k; // ⌈ p / k ⌉ = ⌊ p + k - 1 / k ⌋
        return s;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        
        while (l < r) {
            int mid = (l + r) >> 1;
            if (getHours(piles, mid) <= h) r = mid;
            else l = mid + 1;
        }
    
        return r;
    }
};