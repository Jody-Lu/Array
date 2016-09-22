#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
    	/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    	Solution(ListNode* head) {
            this -> head = head;
    	}

    	/** Returns a random node's value. */
    	int getRandom() {
            int res = head -> val;
            ListNode* node = head -> next;
            int i = 2;
            while(node) {
                int j = rand() % i;
                if(j == 0)
                    res = node -> val;
                i++;
                node = node -> next;
            }
            return res;
    	}
    private:
        ListNode* head;

};

int main() {
    return 0;
}
