#include <cstdio>
#include <queue>

using namespace std;

// 对顶堆：O(log n)
class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> up; // 小根堆，维护区间右半边
    priority_queue<int> down; // 大根堆，维护区间左半边
    
public:
    MedianFinder() {
    
    }
    
    void addNum(int num) {
        if (up.empty() || num < up.top()) {
            down.push(num);
            // 维护 up.size == down.size 或 up.size == down.size + 1
            if (down.size() > up.size()) {
                up.push(down.top());
                down.pop();
            }
        } else {
            up.push(num);
            if (up.size() > down.size() + 1) {
                down.push(up.top());
                up.pop();
            }
        }
    }
    
    double findMedian() {
        int len = up.size() + down.size();
        if (len & 1) return up.top();
        else return (up.top() + down.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf = MedianFinder();
    mf.addNum(1);
    mf.addNum(2);
    printf("%f\n", mf.findMedian()); // 1.5
    mf.addNum(3);
    printf("%f\n", mf.findMedian()); // 2

    return 0;
}