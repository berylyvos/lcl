class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1, c;
        while (n--) {
            c = a + b;
            a = b, b = c;
        }
        return a;
    }
};