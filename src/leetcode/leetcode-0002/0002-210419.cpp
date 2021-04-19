
#include "common.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto p1 = l1, p2 = l2;
        unsigned extra = 0;
        while(true) {
            p1->val += p2->val + extra;
            if (p1->val >= 10) p1->val -= 10, extra = 1;
            else extra = 0;
            if (p1->next == nullptr || p2->next == nullptr)
                break;
            else p1 = p1->next, p2 = p2->next;
        }
        if (p1->next == nullptr)
            p1->next = p2->next;
        while (extra > 0) {
            if (p1->next == nullptr) p1->next = new ListNode(0);
            p1 = p1->next;
            p1->val += extra;
            if (p1->val >= 10) p1->val -= 10, extra = 1;
            else extra = 0;
        }
        return l1;
    }
};

int main() {
    Solution s;
}
