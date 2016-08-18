#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
    	ListNode* rotateRight(ListNode* head, int k) {
            ListNode* t1 = head;
            ListNode* t2 = head;
            ListNode* prev = t2;
            int length = getListLength(head);
            if(!length) return NULL; // NULL list
            k %= length; // when k > len(list)
            if(!k) return head; // k == 0: not rotate
            while(--k > 0) t1 = t1 -> next;
            while(t1->next) {
                prev = t2;
                t2 = t2 -> next;
                t1 = t1 -> next;
            }
            prev -> next = NULL;
            t1 -> next = head;
            return t2;
    	}
    private:
        int getListLength(ListNode* head) {
            if(!head) return 0;
            ListNode* tmp = head;
            int res = 0;
            while(tmp) {
                res++;
                tmp = tmp -> next;
            }
            return res;
        }
};

int main() {
    return 0;
}
