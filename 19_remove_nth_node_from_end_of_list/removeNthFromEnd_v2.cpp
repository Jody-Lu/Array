#include <iostream>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
    	ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode** t1 = &head, *t2 = head;
            for(int i = 1; i < n; ++i) {
                t2 = t2 -> next;
            }
            while(t2 -> next) {
                t1 = &((*t1) -> next);
                t2 = t2 -> next;
            }
            *t1 = (*t1) -> next;
            return head;
        }
};

int main() {
    ListNode* head = new ListNode(0);
    //head -> next = new ListNode(1);
    //head -> next -> next = new ListNode(2);
    Solution sol;
    ListNode* res = sol.removeNthFromEnd(head, 1);
    while(head) {
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}
