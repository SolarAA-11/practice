
#include "common.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto end = copy_if(lists.begin(), lists.end(), lists.begin(), [](const ListNode* l) {
            return l != nullptr;
        });
        lists.erase(end, lists.end());
        auto compare_func = [](const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        };
        priority_queue<ListNode*,vector<ListNode*>, decltype(compare_func)>
            q(lists.begin(), lists.end(), compare_func);
        auto hair = new ListNode(0), p = hair;
        while(!q.empty()) {
            auto top = q.top();q.pop();
            if (top->next != nullptr) q.push(top->next);
            top->next = nullptr;
            p->next = top;
            p = top;
        }
        p = hair->next;
        delete hair;
        return p;
    }
};

int main() {

}