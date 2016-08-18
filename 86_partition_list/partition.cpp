#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
    	ListNode* partition(ListNode* head, int x) {
            ListNode *l1 = new ListNode(-1), *l2 = new ListNode(-1);
            ListNode *t1 = l1, *t2 = l2;
            while(head) {
                if(head->val < x) { 
                    l1 = l1 -> next = head;
                }
                else {
                    l2 = l2 -> next = head;
                }
                head = head -> next;
            }
            // remember to NULL l2's next;
            l2 -> next = NULL;
            l1 -> next = t2 -> next;
            return t1 -> next;
    	}
};
int main() {
    return 0;
}
