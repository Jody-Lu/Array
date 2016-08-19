#include <iostream>

using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//Definition for a binary tree node.
struct TreeNode {
    int val;
	TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* sortedListToBST(ListNode* head) {
            return dfs(head);
            
        }
    private:
        TreeNode* dfs(ListNode* start) {
            if(!start) return NULL;
            ListNode* prevSlow = NULL;
            ListNode* slow = start;
            ListNode* fast = start;

            while(fast->next && fast->next->next) {
                prevSlow = slow;
                slow = slow -> next;
                fast = fast -> next -> next;
            }

            TreeNode* treeNode = new TreeNode(slow->val);

            if(prevSlow) {
                prevSlow -> next = NULL;
                treeNode -> left = dfs(start);
            }
            if(slow->next) {
                treeNode -> right = dfs(slow -> next);
            }
            return treeNode;
        }

};


int main() {
    return 0;
}
