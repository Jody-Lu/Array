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
            ListNode *even = head -> next;
            ListNode *curr = head, *forward = head -> next, *prev = head;
            int count = 1;
            while(forward) {
                count++;
                prev = curr;
                curr -> next = forward -> next;
                curr = forward;
                forward = forward -> next;
            }
            if(count % 2 == 0)
                prev -> next = even;
            else
                curr -> next = even;
            return head;
    	}
};

int main() {
    return 0;
}
