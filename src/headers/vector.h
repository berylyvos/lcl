#include <cstdio>
#include <vector>

using namespace std;

void print_vec(const vector<int>& vec) {
    int n = vec.size(), i = 0;
    while (i < n - 1) printf("%d, ", vec[i ++]);
    printf("%d\n", vec[i]);
}