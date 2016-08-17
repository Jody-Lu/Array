#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
	public:
    	ListNode* mergeKLists(vector<ListNode*>& lists) {
            int first = 0, last = lists.size();
            if(!last) return NULL;
            mylists = lists;
            ListNode* res = mergeKListUtil(first, last);
            return res;
    	}
        ListNode* mergeKListUtil(int begin, int end) {
            int mid = (begin + end) / 2;
            ListNode* l1, *l2;
            if(end - begin > 2) {
                l1 = mergeKListUtil(begin, mid);
                l2 = mergeKListUtil(mid, end);
            }
            else if(end - begin == 2) {
                l1 = mylists[begin];
                l2 = mylists[begin + 1];
            }
            else return mylists[begin];

            return mergeTwoList(l1, l2);
        }
    private:
        ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
            ListNode* res = new ListNode(-1);
            ListNode* tmp = res;
            while(l1 && l2) {
                if(l2->val > l1->val) {
                    tmp -> next = l1;
                    l1 = l1 -> next;
                }
                else {
                    tmp -> next = l2;
                    l2 = l2 -> next;
                }
                tmp = tmp -> next;
            }
            tmp -> next = l1? l1 : l2;
            return res -> next;
        }
        vector<ListNode*> mylists;

};

int main() {
    int a = 5 / 2;
    cout << a << endl;
    /**
    int arr[] = {1, 2, 3, 4};
    vector<int> v(arr, arr + 4);
    vector<int> sub(&v[0], &v[2]);
    for(vector<int>::iterator it = sub.begin(); it != sub.end(); it++) {
        cout << *it << endl;
    }
    **/
}
