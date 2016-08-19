#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
	public:
    	ListNode* reverseBetween(ListNode* head, int m, int n) {
    	    ListNode* go = head;
            while(--m) {
                go = go -> next;
                n--;
            }
            ListNode* rHead = go;
            while(--n) {
                go = go -> next;
            }
            ListNode* rTail = go;
            reversePart(rHead, rTail, rTail -> next);
            return head;
        }
    private:
        ListNode* reversePart(ListNode* head, ListNode* tail, ListNode* tailNext) {
            ListNode* prev = tailNext;
            ListNode* curr;
            while(head != tail) {
                curr = head;
                head = head -> next;
                curr -> next = prev;
                prev = curr;
            }
            return prev;
        }
};

int main() {
    return 0;
}
