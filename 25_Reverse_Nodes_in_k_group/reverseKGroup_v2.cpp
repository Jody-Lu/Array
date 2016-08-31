#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* curr = head;
            int count = 0;
            /*just go ahead*/
            while(curr != NULL && count != k) {
                curr = curr -> next;
                count++;
            }
            /* count == k: there are enough nodes*/
            /* Otherwise, return head directly. */
            if(count == k) {
                curr = reverseKGroup(curr, k);
                /* Reverse Here. */
                while(count-- > 0) {
                    ListNode* tmp = head -> next;
                    head -> next = curr;
                    curr = head;
                    head = tmp;
                }
                /* curr now point to the first node of the reverse result. */
                /* move head to curr. */ 
                head = curr;
            }
            return head;
        }

};

int main() {
    return 0;
}
