#include <cstdio>
#include <headers/vector.h>

using namespace std;

class Solution {
public:
    void move(int n, vector<int>& src, vector<int>& dst, vector<int>& via) {
        if (n == 1) {
            dst.push_back(src.back());
            src.pop_back();
            return;
        }
        move(n - 1, src, via, dst);
        move(1, src, dst, via);
        move(n - 1, via, dst, src);
    }
    
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        move(A.size(), A, C, B);
    }
};

static void hanoi(int n, char src, char dst, char via) {
    if (n == 1) {
        printf("%c -> %c\n", src, dst);
        return;
    }
    hanoi(n - 1, src, via, dst);
    hanoi(1, src, dst, via);
    hanoi(n - 1, via, dst, src);
}

int main() {
    hanoi(3, 'A', 'C', 'B');
    // A -> B
    // A -> C
    // B -> C
    // A -> B
    // C -> A
    // C -> B
    // A -> B

    vector<int> A = {2, 1, 0}, B, C;
    Solution().hanota(A, B, C);
    
    print_vec(A);
    print_vec(B);
    print_vec(C);
    
    return 0;
}