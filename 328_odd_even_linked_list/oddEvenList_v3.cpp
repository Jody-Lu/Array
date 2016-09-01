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
            if(!head || !(head -> next)) return head;
            ListNode *even = head -> next, *odd = head;
            ListNode *evenHead = head -> next;
            while(odd -> next && even -> next) {
                odd -> next = even -> next;
                odd = odd -> next;
                even -> next = odd -> next;
                even = even -> next;
            }
            odd -> next = evenHead;
            return odd;
    	}
};