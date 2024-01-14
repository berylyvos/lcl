#include "headers/list.h"
// https://leetcode.cn/problems/remove-duplicates-from-sorted-list

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;

        auto pre = head, p = pre->next;
        for (; p; p = p->next)
            if (p->val != pre->val)
                pre = pre->next = p;
        
        pre->next = nullptr;
        return head;
    }
};