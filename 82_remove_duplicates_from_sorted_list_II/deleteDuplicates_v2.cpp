#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode** runner = &head;

            if(!head || !(head->next)) { return head; }

            while(*runner) {
                if((*runner)->next && (*runner)->val == (*runner)->next->val) {
                    ListNode* tmp = *runner;
                    while(tmp && (*runner)->val == tmp->val) {
                        tmp = tmp->next;
                    }
                    *runner = tmp;
                }
                else {
                    runner = &((*runner)->next);
                }
            }

            return head;
        }
};
