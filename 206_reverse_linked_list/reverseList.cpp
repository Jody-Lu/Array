#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
    	ListNode* reverseList(ListNode* head) {
            ListNode* prev = NULL;
            ListNode* curr;
            while(head) {
                curr = head;
                head = head -> next;
                curr -> next = prev;
                prev = curr
            }
            return prev;
    	}
};
