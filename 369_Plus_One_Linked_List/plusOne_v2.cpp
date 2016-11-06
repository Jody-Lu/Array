/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        head = reverseList(head);
        ListNode** c1 = &head;
        while(*c1) {
            if((*c1)->val == 9) {
                (*c1)->val = 0;
            }
            else {
                (*c1)->val++;
                return reverseList(head);
            }
            c1 = &((*c1)->next);
        }

        ListNode* tmp = new ListNode(0);
        tmp->next = head;
        head = tmp;
        head = reverseList(head);
        head->val = 1;

        return head;

    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr, *prev = NULL;
        while(head) {
            curr = head;
            head = head->next;
            curr->next = prev;
            prev = curr;
        }

        return prev;
    }
};