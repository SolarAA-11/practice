
#include "common.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto hair = new ListNode(0), p1 = hair, p2 = hair;
        hair->next = head;
        for (int i = 0; i < n; ++i)
            p2 = p2->next;
        while(p2->next != nullptr)
            p1 = p1->next, p2 = p2->next;
        p2 = p1->next;
        p1->next = p2->next;
        delete p2;

        p1 = hair->next;
        delete hair;
        return p1;
    }
};

int main() {
    Solution s;
}
