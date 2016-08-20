#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        newHead -> next = head;
        ListNode* pre = newHead;
        ListNode* cur = head;
        while(cur) {
            if(cur -> next && cur -> next -> val < cur -> val) {
                while(pre -> next && pre -> next -> val < cur -> next -> val) {
                    pre = pre -> next;
                }
                /* Insert cur -> next after pre. */
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                /* Move pre back to new_Head. */
                pre = newHead;
            }
            else cur = cur -> next;
        }
        ListNode* res = newHead -> next;
        delete newHead;
        return res;
    }
};

int main() {
    return 0;
}
