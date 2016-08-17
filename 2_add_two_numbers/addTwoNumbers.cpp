#include <iostream>

using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
    	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int len1 = getListLength(l1), len2 = getListLength(l2);
            int carrier = 0;
            if(len1 > len2) {
                addZeroes(l2, len1 - len2);
            }
            else if(len2 > len1) {
                addZeroes(l1, len2 - len1);
            }

            ListNode *head = l1, *prev = NULL;

            while(l1) {
                prev = l1;
                int val = l1 -> val + l2 -> val + carrier;
                if(val >= 10) {
                    l1 -> val = val - 10;
                    carrier = 1;
                }
                else {
                    l1 -> val = val;
                    carrier = 0;
                }
                l1 = l1 -> next;
                l2 = l2 -> next;
            }
            
            if(carrier >= 1) {
                if(!prev->next) prev -> next = new ListNode(carrier);
                else prev -> next -> val += carrier;
            }
            return head;
    	}
    private:
        void addZeroes(ListNode* head, int n) {
            ListNode* tmp = head;
            while(tmp->next) tmp = tmp -> next;
            while(n) {
                tmp -> next = new ListNode(0);
                tmp = tmp -> next;
                n--;
            }
        }
        int getListLength(ListNode* head) {
            int length = 0;
            ListNode* tmp = head;
            while(tmp)
            {
                length++;
                tmp = tmp -> next;
            }
            return length;
        }
};

int main() {
    ListNode* l1 = new ListNode(9);
    ListNode* l2 = new ListNode(2);
    Solution sol;
    ListNode* head = sol.addTwoNumbers(l1, l2);
    cout << head -> val << endl;
    cout << head -> next -> val << endl;
}
