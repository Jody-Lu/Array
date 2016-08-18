#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
    	ListNode* swapPairs(ListNode* head) {
            ListNode* pre = new ListNode(-1);
            ListNode* dummy = pre;
            pre -> next = head;
            ListNode *a, *b;
            while(pre->next && pre->next->next) {
                a = pre -> next;
                b = a -> next;
                pre -> next = b;
                ListNode* tmp = b -> next;
                b -> next = a;
                a -> next = tmp;
                pre = a;
            }
            return dummy -> next;
    	}
};

int main() {
    Solution sol;
    return 0;
}
