class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode** c1 = &l1;
        ListNode** c2 = &l2;
        ListNode* res;
        ListNode** d = &res;
        int sum = 0;

        while(*c1 || *c2 || sum >= 10) {
            sum /= 10;

            if(*c1) {
                sum += (*c1)->val;
                c1 = &((*c1)->next);
            }

            if(*c2) {
                sum += (*c2)->val;
                c2 = &((*c2)->next);
            }

            *d = new ListNode(sum % 10);
            d = &((*d)->next);
        }

        return res;
    }
};