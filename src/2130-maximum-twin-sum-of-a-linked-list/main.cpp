#include "common/list.cpp"

// https://leetcode.cn/problems/maximum-twin-sum-of-a-linked-list/

class Solution {
public:
    int pairSum(ListNode *head) {
        // find mid
        auto fast = head, mid = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            mid = mid->next;
        }

        // reverse the second half
        ListNode *q = mid, *pre = nullptr, *nxt;
        while (q) {
            nxt = q->next;
            q->next = pre;
            pre = q;
            q = nxt;
        }
        q = pre;

        // find all twin sums
        int res = 0;
        auto p = head;
        while (q) {
            res = max(res, p->val + q->val);
            p = p->next;
            q = q->next;
        }

        return res;
    }
};