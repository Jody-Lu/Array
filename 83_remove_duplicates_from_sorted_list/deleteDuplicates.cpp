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
            ListNode* tmp = head;
            while(tmp && tmp->next) {
                if(tmp->val == tmp->next->val) {
                    ListNode* n = tmp -> next -> next;
                    delete tmp -> next;
                    tmp -> next = n;
                }
                else {
                    tmp = tmp -> next;
                }
            }

            return head;
    	}
};
