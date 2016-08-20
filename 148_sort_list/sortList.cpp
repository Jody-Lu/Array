#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
	public:
    	ListNode* sortList(ListNode* head) {
            /* Divide the list into two part. */
            if(!head || !head->next) return head;
            ListNode* mid = findMiddle(head);
            ListNode* sec = mid -> next;
            mid -> next = NULL;
            /* If middle == head, the list length is 2. */
            if(head != mid) {
                head = sortList(head);
                sec = sortList(sec);
            }
            /* Merge the two lists. */
            return merge(head, sec);
    	}
    private:
        ListNode* findMiddle(ListNode* head) {
            ListNode *slow = head, *fast = head;
            while(fast -> next && fast -> next -> next) {
                slow = slow -> next;
                fast = fast -> next -> next;
            }
            return slow;
        }

        ListNode* merge(ListNode* l1, ListNode* l2) {
            ListNode* res = new ListNode(-1);
            ListNode* temp = res;
            while(l1 && l2) {
                if(l1 -> val > l2 -> val) {
                    temp -> next = l2;
                    l2 = l2 -> next;
                }
                else {
                    temp -> next = l1;
                    l1 = l1 -> next;
                }
                temp = temp -> next;
            }
            
            if(l1) temp -> next = l1;
            if(l2) temp -> next = l2;
            return res -> next;
        }
};

int main() {
    return 0;
}
