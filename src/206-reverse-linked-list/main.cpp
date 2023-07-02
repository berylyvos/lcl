#include "common/list.cpp"

// https://leetcode.cn/problems/reverse-linked-list/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *pre = nullptr, *cur = head, *nxt;

        while (cur) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        return pre;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        auto reverseHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return reverseHead;
    }
};