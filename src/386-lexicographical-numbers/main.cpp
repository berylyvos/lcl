#include "headers/vector.h"

using namespace std;

// 想象一颗 字典序Trie, DFS即可

//             root
//   
//   1             2       3 ... 9
// 
// 0 1 2 ...9   0 1 2...9
class Solution {
public:
    vector<int> res;

    void dfs(int cur, const int& n) {
        if (cur > n) return;
        res.push_back(cur);
        for (int i = 0; i <= 9; ++ i) dfs(cur * 10 + i, n);
    }

    // O(n) O(logn)
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; ++ i) dfs(i, n);
        return res;
    }

    // O(n) O(1)
    vector<int> lexicalOrder1(int n) {
        int cur = 1, cnt = 0;
        while (cnt < n) {
            while (cur <= n) {
                res.push_back(cur);
                ++ cnt;
                cur *= 10; // 搜下一层
            }
            
            // 个位为9说明当前层搜完了，返回上一层
            while (cur % 10 == 9 || cur > n) cur /= 10;
            
            cur ++; // 搜当前层的下一个数
        }
        return res;
    }
};

int main()
{
    // 1 10 11 12 13 14 15 16 17 18 19 2 20 21 22 3 4 5 6 7 8 9
    print_vec(Solution().lexicalOrder1(22));
    return 0;
}