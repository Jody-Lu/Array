#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
	public:
    	ListNode* removeElements(ListNode* head, int val) {
            ListNode *dummy = new ListNode(val + 1) ;
            dummy -> next = head;
            ListNode *temp = dummy, *prev = NULL;
            while(temp) {
                if(temp -> val == val) {
                    prev -> next = temp -> next;
                }
                else prev = temp;
                temp = temp -> next;
            }

            return dummy -> next;
    	}
};
