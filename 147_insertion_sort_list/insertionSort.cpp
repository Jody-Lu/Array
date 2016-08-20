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
        ListNode* p = new ListNode(0);
        ListNode* dummy = p;
        dummy -> next = head;
        ListNode* cur = head; 
        while(cur && cur-> next) {
            int val = cur -> next -> val;
            if(cur -> val < val) {
                cur = cur -> next;
                continue;
            }
            if(p->val > val) {
                p = dummy;
            }
            while(p -> next -> val < val) {
                p = p -> next;
            }

            ListNode* newNode = cur -> next;
            cur -> next = newNode -> next;
            newNode -> next = p -> next;
            p -> next = newNode;
        }

        return dummy -> next;
    } 
};

int main() {
    return 0;
}
