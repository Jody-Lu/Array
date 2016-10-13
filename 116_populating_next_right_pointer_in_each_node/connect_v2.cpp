#include <list>
#include <vector>

using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        list<TreeLinkNode*> curr, next;
        vector<TreeLinkNode*> level;
        if(!root) return;
        curr.push_front(root);
        while(!curr.empty()) {
            while(!curr.empty()) {
                TreeLinkNode* node = curr.back();
                curr.pop_back();
                /* If level is not empty, connect its last element to the node in the same level. */
                if(!level.empty()) level.back() -> next = node;
                level.push_back(node);
                if(node->left) next.push_front(node->left);
                if(node->right) next.push_front(node->right);
            }
            /* connect the last element in level to NULL. */
            level.back() -> next = NULL;
            level.clear();
            swap(curr, next);
        }
    }
};

int main() {
    return 0;
}
