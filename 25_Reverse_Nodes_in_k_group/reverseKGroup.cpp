#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            vector<pair<ListNode*, ListNode*> > map;
            ListNode *start = head, *end = head, *prev = head;
            if(k == 0 || !head) return head;
            while(head) {
                int count = 1;
                while(count < k) {
                    if(!end -> next) break;
                    end = end -> next;
                    count++;
                }
                if(count == k) {
                    start = end -> next;
                    end -> next = NULL;
                    map.push_back(make_pair(reverseList(prev), prev));
                    head = start;
                    prev = start;
                    end = start;
                }
                else {
                    map.push_back(make_pair(start, (ListNode*)NULL));
                    head = end -> next;
                }
            }
            ListNode* res = map[0].first;
            for(int i = 0; i < map.size() - 1; i++)
                map[i].second -> next = map[i + 1].first;

            return res;
        }

    private:
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = NULL;
            ListNode* curr;
            while(head) {
                curr = head;
                head = head -> next;
                curr -> next = prev;
                prev = curr;
            }
            return prev;
        }
};

int main() {
    ListNode* head = new ListNode(1);
    head -> next =  new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    int k = 4;
    Solution sol;
    sol.printList(sol.reverseKGroup(head, k));
    return 0;
}
