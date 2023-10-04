#include <vector>
// https://leetcode.cn/problems/design-circular-deque/

class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        q.resize(k + 1);
        cap = k + 1;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        hh = get(hh - 1);
        q[hh] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        q[tt] = value;
        tt = get(tt + 1);
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        hh = get(hh + 1);
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        tt = get(tt - 1);
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : q[hh];
    }
    
    int getRear() {
        return isEmpty() ? -1 : q[get(tt - 1)];
    }
    
    bool isEmpty() {
        return hh == tt;
    }
    
    bool isFull() {
        return get(hh - 1) == tt;
    }

private:
    std::vector<int> q;
    int hh{0};
    int tt{0};
    int cap;

    const int get(int idx) const { return (idx + cap) % cap; }
};