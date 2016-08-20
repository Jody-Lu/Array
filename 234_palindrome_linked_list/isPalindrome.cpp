#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
	public:
    	bool isPalindrome(ListNode* head) {
            if(!head) return true;
            /*Divide the list into two parts. */
            ListNode *mid = findMiddle(head);
            ListNode *head2 = reverseList(mid->next);
            mid -> next = NULL;
            /* Check whether each node are equal. */
            while(head && head2) {
                if(head -> val != head2 -> val) return false;
                head = head -> next;
                head2 = head2 -> next;
            }
            return true;
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

        ListNode* reverseList(ListNode* head) {
            ListNode *prev = NULL, *curr;
            while(head) {
                curr = head;
                head = head -> next;
                curr -> next = prev;
                prev = curr;
            }
            return prev;
        }
};
