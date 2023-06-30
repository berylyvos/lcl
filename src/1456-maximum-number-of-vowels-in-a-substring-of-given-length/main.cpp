#include <string>
using namespace std;

// 给你字符串 s 和整数 k 。
// 请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。
// https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        // auto isVowel = [vowels = "aeiou"s](char c) {
        //     return vowels.find(c) != string::npos;
        // };

        int res = 0, cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += isVowel(s[i]);
        }
        res = cnt;

        for (int i = k; i < s.size(); ++i) {
            cnt += isVowel(s[i]) - isVowel(s[i - k]);
            res = max(res, cnt);
        }
        return res;
    }
};