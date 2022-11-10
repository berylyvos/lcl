#include <cstdio>
#include <vector>

using namespace std;

// O(log(n) * log(n))
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        vector<int> num;
        while (n) num.push_back(n % 10), n /= 10;
        // n = 1204
        // num = {4, 0, 2, 1}
        int len = num.size();
        for (int i = len - 1; i >= 0; -- i) {
            int left = 0, right = 0, t = 1;
            for (int j = len - 1; j > i; -- j) left = left * 10 + num[j];
            for (int j = i - 1; j >= 0; -- j) right = right * 10 + num[j], t *= 10;
            
            res += left * t; // 左：0 ~ (left - 1)  右：0 ~ (t - 1)
            if (num[i] == 1) res += right + 1; // 左：left, 右：0 ~ right
            else if (num[i] > 1) res += t;     // 左：left, 右：0 ~ (t - 1)
        }
        return res;
    }
};

int main()
{
    printf("%d\n", Solution().countDigitOne(13015)); // 8924
    printf("%d\n", Solution().countDigitOne(1e9));   // 900000001
    return 0;
}