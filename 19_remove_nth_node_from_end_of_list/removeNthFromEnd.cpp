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
            int len = getListLength(head);
            int diff = len - n;
            if(!diff) return NULL;
            ListNode *forward = head, *prev = NULL;
            while(diff) {
                prev = forward;
                forward = forward -> next;
                diff--;
            }
            prev -> next = forward -> next;
            delete forward;
            return head;
    	}
    private:
        int getListLength(ListNode* head) {
            ListNode* tmp = head;
            int len = 0;
            while(tmp) {
                len++;
                tmp = tmp -> next;
            }
            return len;
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
