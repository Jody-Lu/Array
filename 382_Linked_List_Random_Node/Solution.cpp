#include <iostream>
#include <vector>

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
            while(head) {
                list.push_back(head -> val);
                head = head -> next;
            }
            size = list.size();
    	}

    	/** Returns a random node's value. */
    	int getRandom() {
            int index = rand() % size;
            return list[index];
    	}
    private:
        vector<int> list;
        int size;
};

int main() {
    return 0;
}
