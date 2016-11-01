class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1; // store l1
        stack<int> st2; // store l2
        ListNode* res = new ListNode(-1);
        ListNode* d = res;
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
        while(!st1.empty() || !st2.empty()) {
            sum /= 10;
            if(!st1.empty()) {
                sum += st1.top();
                st1.pop();
            }
            
            if(!st2.empty()) {
                sum += st2.top();
                st2.pop();
            }
            
            d->next = new ListNode(sum % 10);
            d = d->next;
        }
        
        // check whether there is carry bit 
        if(sum >= 10) {
            d->next = new ListNode(sum / 10);
        }
        
        // delete the dummy node
        d = res;
        res = res->next;
        delete d;
        
        // reverse the result
        head = reverseList(res); 
        
        return head;
    }
private:
    ListNode* reverseList(ListNode *head) {
        ListNode *prev = NULL, *curr;
        while(head) {
            curr = head;
            head = head->next;
            curr->next = prev;
            prev = curr;
        }
        return prev;
    }
};