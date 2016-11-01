class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* newHead = reverseList(head);
        ListNode* tmp = newHead;
        int sum = 1;
        while(true) {
            sum += tmp->val;
            tmp->val = sum % 10;
            if(sum < 10 || !(tmp->next)) {
                break;
            }
            tmp = tmp->next;
            sum /= 10;
        }
        
        if(sum >= 10) {
            tmp->next = new ListNode(sum / 10);
        }
        
        return reverseList(newHead);
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