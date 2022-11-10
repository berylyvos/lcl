#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 哈希表：O(10 * n)
    vector<string> findRepeatedDnaSequences1(string s) {
        unordered_map<string, int> hash;
        vector<string> res;
        for (int i = 0; i + 10 <= (int)s.size(); ++ i) {
            auto str = s.substr(i, 10);
            if (++ hash[str] == 2) res.emplace_back(str);
        }
        return res;
    }

    // 字符串哈希：O(n)
    vector<string> findRepeatedDnaSequences2(string s) {
        using ULL = unsigned long long;
        unordered_map<ULL, int> hash;
        const int P = 131;
        vector<string> res;
        for (int i = 0; i + 10 <= (int)s.size(); ++ i) {
            ULL h = 0;
            for (int j = i; j < i + 10; ++ j) h = h * P + s[j];
            if (++ hash[h] == 2) res.emplace_back(s.substr(i, 10));
        }
        return res;
    }
};

int main() {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    auto res = Solution().findRepeatedDnaSequences2(s);
    for (auto x: res) printf("%s  ", x.c_str());
    // "AAAAACCCCC","CCCCCAAAAA"
    printf("\n");
    return 0;
}