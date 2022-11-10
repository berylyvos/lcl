#include "headers/vector.h"

using namespace std;

// 上下翻转对称，上半部分末尾补0，下半部分末尾补1

// n = 0
// 0

// n = 1
// 0
// 1

// n = 2
// 0 0
// 1 0
// 1 1
// 0 1

// n = 3
// 0 0 0
// 1 0 0
// 1 1 0
// 0 1 0
// 0 1 1
// 1 1 1
// 1 0 1
// 0 0 1
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res {0};
        while (n --) {
            for (int i = res.size() - 1; i >= 0; -- i) {
                res[i] <<= 1;
                res.push_back(res[i] + 1);
            }
        }
        return res;
    }
};

int main() {
    print_vec(Solution().grayCode(3)); // 0 4 6 2 3 7 5 1
    return 0;
}