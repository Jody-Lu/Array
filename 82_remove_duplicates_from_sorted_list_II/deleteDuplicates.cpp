#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
    	ListNode* deleteDuplicates(ListNode* head) {
            if(!head) return NULL;
            ListNode* prev = new ListNode(-1);
            ListNode* dummy = new ListNode(head->val + 1);
            dummy -> next = head;
            prev -> next = dummy;
            ListNode* tmp = dummy;
            while(tmp && tmp -> next) {
                if(tmp->val == tmp->next->val) {
                    while(tmp && tmp->next && (tmp->val == tmp->next->val)) {
                        tmp = tmp -> next;
                    }
                    tmp = tmp -> next;
                    prev -> next = tmp;
                }
                else {
                    prev = prev -> next;
                    tmp = tmp -> next;
                }
            }

            return dummy -> next;
    	}
};
