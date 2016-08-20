#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
    public:
        void reorderList(ListNode* head) {
            ListNode* mid = findMiddle(head);
            ListNode* sec = mid -> next;
            mid -> next = NULL;
            sec = reverseList(sec);

            ListNode* tmp = head, *next_middle;
            while(sec) {
                next_middle = sec -> next;
                sec -> next = tmp -> next;
                tmp -> next = sec;
                tmp = sec -> next;
                sec = next_middle;
            }
        }
    private:
        ListNode* reverseList(ListNode* head) {
            ListNode *prev = NULL, *curr;
            while(head) {
                curr = head;
                head = head -> next;
                curr -> next = prev;
                prev = curr;
            }
            return prev;
        }
        ListNode* findMiddle(ListNode* head) {
            ListNode* slow = head, *fast = head;
            while(slow && fast && fast->next) {
                slow = slow -> next;
                fast = fast -> next -> next;
            }
            return slow;
        }
};


int main() {
    return 0;
}
