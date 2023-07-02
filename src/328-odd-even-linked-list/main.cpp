#include "common/list.cpp"
using namespace std;

// https://leetcode.cn/problems/odd-even-linked-list/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        auto evenHead = head->next;
        auto odd = head, even = evenHead;
        
        while (even && even->next) {
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};

int main() {
    auto head = Solution().oddEvenList(vec2list(vector<int>{1,2,3,4,5}));
    print_list(head); // 1 -> 3 -> 5 -> 2 -> 4
    head = Solution().oddEvenList(vec2list(vector<int>{1,2}));
    print_list(head); // 1 -> 2
}