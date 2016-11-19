class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1; // store l1
        stack<int> st2; // store l2
        ListNode* prev = NULL;
        ListNode* head;
        int sum = 0;

        // push l1's elements into stack
        while(l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }

        // push l2's element into stack
        while(l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }

        // calculate
        while(!st1.empty() || !st2.empty() || sum >= 10) {
            sum /= 10;
            if(!st1.empty()) {
                sum += st1.top();
                st1.pop();
            }

            if(!st2.empty()) {
                sum += st2.top();
                st2.pop();
            }

            head = new ListNode(sum % 10);
            head->next = prev;
            prev = head;
        }

        return head;
    }
};