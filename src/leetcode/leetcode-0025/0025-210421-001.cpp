
#include "common.h"

class Solution {
private:
    using pnode = ListNode*;
    pnode reverse(pnode head) {
        decltype(head) p1 = nullptr, p2 = head;
        while (p2 != nullptr) {
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
        auto next_k = [=](pnode p) {
            for (int i = 0;i < k && p; ++i) {
                p = p->next;
            }
            return p;
        };
        while (true) {
            p2 = next_k(p2);
            if (!p2) break;
            auto tmp = p2->next;
            p2->next = nullptr;
            reverse(p1->next);

            auto tmp2 = p1->next;
            p1->next = p2;
            tmp2->next = tmp;
            p1 = p2 = tmp2;
        }
        p1 = hair->next;
        delete hair;
        return p1;
    }
};

int main() {
    Solution s;
}
