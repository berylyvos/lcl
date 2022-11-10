#include <cstdio>
#include <string>

using namespace std;

// （贪心，单调栈）O(n)
//  abc1xxx < abc3xxx 尽可能把左边比自己大的数删掉（消除逆序）
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for (const auto &x: num) {
            while (k && res.size() && res.back() > x) {
                -- k;
                res.pop_back();
            }
            res.push_back(x);
        }
        // k 有剩余，此时整个数字序列非递减(↑)
        // 要想数最小，则将末尾 k 个数删掉
        while (k --) res.pop_back();

        // 删除前导零
        k = 0;
        while (k < res.size() && res[k] == '0') ++ k;
        if (k == (int)res.size()) return "0"; // 整个序列都为0
        return res.substr(k);
    }
};

int main()
{
    string s = "1432219";
    int k = 3;
    printf("%s\n", Solution().removeKdigits(s, k).c_str()); // 1219

    return 0;
}