
#include "common.h"

class Solution {
private:
    ListNode* reverse(ListNode* head) {
        decltype(head) p2 = head, p1 = nullptr;
        while(p2 != nullptr) {
            auto tmp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }
        return p1;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto hair = new ListNode(0), p1 = hair, p2 = hair;
        hair->next = head;
        for (int i = 0; i < k && p2; ++i)
            p2 = p2->next;
        while (p2) {
            auto tmp = p2->next, p3 = p1->next;
            p2->next = nullptr;
            reverse(p3);
            p1->next = p2;
            p3->next = tmp;
            p1 = p3;
            p2 = p3;
            for (int i = 0; i < k && p2; ++i) p2 = p2->next;
        }
        head = hair->next;
        delete hair;
        return head;
    }
};

int main() {
    Solution s;
}
