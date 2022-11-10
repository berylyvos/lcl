#include <cstdio>
#include <vector>

using namespace std;

//    Char. number range  |        UTF-8 octet sequence
//       (hexadecimal)    |              (binary)
//    --------------------+---------------------------------------------
//    0000 0000-0000 007F | 0xxxxxxx
//    0000 0080-0000 07FF | 110xxxxx 10xxxxxx
//    0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
//    0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (const auto& x: data) {
            if (!cnt) {
                if (x >> 5 == 0b110) cnt = 1;        // 110xxxxx
                else if (x >> 4 == 0b1110) cnt = 2;  // 1110xxxx
                else if (x >> 3 == 0b11110) cnt = 3; // 11110xxx
                else if (x >> 7) return false;       // 10000000，不符题意
            } else {
                if (x >> 6 != 0b10) return false;
                -- cnt;
            }
        }
        return cnt == 0;
    }
};

int main() 
{
    // 数据表示字节序列:11000101 10000010 00000001。
    // 这是有效的 utf-8 编码，为一个 2 字节字符，跟着一个 1 字节字符。
    vector<int> data = {197,130,1};
    printf("%d\n", Solution().validUtf8(data));
    return 0;
}