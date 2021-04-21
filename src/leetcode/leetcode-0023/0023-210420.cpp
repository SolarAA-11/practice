
#include "common.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode *node1, ListNode *node2) {
            return node1->val > node2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for (const auto &item : lists)
            if (item != nullptr)
                pq.push(item);
        auto hair = new ListNode(0), p = hair;
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            if (top->next != nullptr) pq.push(top->next);
            p->next = top;
            p = p->next;
        }
        p = hair->next;
        delete hair;
        return p;
    }
};

int main() {
    Solution s;
}
