#include <deque>
using namespace std;
// https://leetcode.cn/problems/design-front-middle-back-queue

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        lq.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        if (lq.size() < rq.size()) {
            lq.push_back(val);
        } else {
            rq.push_front(val);
        }
    }
    
    void pushBack(int val) {
        rq.push_back(val);
        balance();
    }
    
    int popFront() {
        if (rq.empty()) {
            return -1;
        }
        int res;
        if (lq.empty()) {
            res = rq.front();
            rq.pop_front();
        } else {
            res = lq.front();
            lq.pop_front();
        }
        balance();
        return res;
    }
    
    int popMiddle() {
        if (rq.empty()) {
            return -1;
        }
        int res;
        if (lq.size() == rq.size()) {
            res = lq.back();
            lq.pop_back();
        } else { // lq.size() + 1 == rq.size()
            res = rq.front();
            rq.pop_front();
        }
        return res;
    }
    
    int popBack() {
        if (rq.empty()) {
            return -1;
        }
        int res = rq.back();
        rq.pop_back();
        balance();
        return res;
    }

private:
    deque<int> lq, rq;

    // maintain  0 <= rq.size() - lq.size() <= 1
    void balance() {
        if (lq.size() > rq.size()) {
            rq.push_front(lq.back());
            lq.pop_back();
            // lq.size() + 1 == rq.size()
        } else if (lq.size() + 1 < rq.size()) {
            lq.push_back(rq.front());
            rq.pop_front();
            // lq.size() == rq.size()
        }
    }
};