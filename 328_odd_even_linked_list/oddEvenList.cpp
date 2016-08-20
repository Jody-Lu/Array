#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
	public:
    	ListNode* oddEvenList(ListNode* head) {
            ListNode *l1 = new ListNode(-1);
            ListNode *l2 = new ListNode(-1);
            ListNode *dummy1 = l1, *dummy2 = l2;

            /* Divide the list into two parts. */
            while(head && head -> next) {
                l1 -> next = head;
                l1 = l1 -> next;
                l2 -> next = head -> next;
                l2 = l2 -> next;
                head = head -> next -> next;
            }
            /* If head != NULL, there are odd nodes. */
            if(head) { 
                l1 -> next = head;
                l1 = l1 -> next;
            }
            l1 -> next = dummy2 -> next;
            /* Remember to set l2 -> next to NULL*/
            l2 -> next = NULL;
            ListNode* res = dummy1 -> next;
            return res;
    	}
};

int main() {
    return 0;
}
