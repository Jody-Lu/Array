#include <queue>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};


class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<int> pq;
            ListNode *head, *res = NULL, *dummy = NULL;

            for(int i = 0; i < lists.size(); i++) {
                for(head = lists[i]; head != NULL; head = head->next) {
                    pq.push(head->val);
                }
            }
            while(!pq.empty()) {
                res = new ListNode(pq.top());
                pq.pop();
                res->next = dummy;
                dummy = res;
            }
            return res;
        }
};


int main() {
    int myints[] = {10, 60, 50, 20};

    priority_queue<int, vector<int>, greater<int> > PQ(myints, myints + 4);

    cout << PQ.top() << endl;

    PQ.pop();

    cout << PQ.top() << endl;
    return 0;
}
