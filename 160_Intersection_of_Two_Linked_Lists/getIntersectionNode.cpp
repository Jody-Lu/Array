#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode *goA = headA, *goB = headB;
            
            /* Either goA or goB is NULL, the remaining is the longer one. */
            while(goA && goB) {
                goA = goA -> next;
                goB = goB -> next;
            }
            /* cut the remaining number.*/
            while(goA) {
                goA = goA -> next;
                headA = headA -> next;
            }
            while(goB) {
                goB = goB -> next;
                headB = headB -> next;
            }
            /* Now, both A and B are with the same distance with intersection node. */
            while(headA != headB) {
                headA = headA -> next;
                headB = headB -> next;
            }
            return headA;
        }
};

int main() {
    return 0;
}
