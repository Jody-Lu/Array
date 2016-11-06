class Solution {
    public:
        void connect(TreeLinkNode *root) {
            TreeLinkNode* head = NULL;
            TreeLinkNode* prev = NULL;
            TreeLinkNode* curr = root;

            while(curr != NULL) {
                while(curr != NULL) {
                    // left child
                    if(curr->left != NULL) {
                        if(prev != NULL) {
                            prev->next = curr->left;
                        }
                        else {
                            head = curr->left;
                        }
                        pre = curr->left;
                    }
                    // right child
                    if(curr->right != NULL) {
                        if(prev != NULL) {
                            prev->next = curr->right;
                        }
                        else {
                            head = curr->right;
                        }
                    }

                    curr = curr->next;
                }
                curr = head;
                head = NULL;
                prev = NULL;
            }
        }
};
