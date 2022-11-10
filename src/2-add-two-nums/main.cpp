#include <vector>
#include "headers/list.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1), cur = dummy;
        int t = 0; // 进位

        while (l1 || l2 || t) {
            if (l1) t += l1->val, l1 = l1->next;
            if (l2) t += l2->val, l2 = l2->next;
            cur->next = new ListNode(t % 10);
            cur = cur->next;
            t /= 10;
        }
        return dummy->next;
    }
};

int main() {
    const vector<int> v1 = {9,9,9,9,9,9,9}, v2= {9,9,9,9};

    auto l1 = vec2list(v1), l2 = vec2list(v2);
    auto res = Solution().addTwoNumbers(l1, l2);
    
    // [8,9,9,9,0,0,0,1]
    print_list(res);

    delete_list(l1);
    delete_list(l2);
    delete_list(res);
    
    return 0;
}