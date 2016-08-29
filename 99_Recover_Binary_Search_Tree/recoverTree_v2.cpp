#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
  	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void recoverTree(TreeNode* root) {
        	TreeNode *first, *middle, *last, *prev;
            first = middle = last = prev = NULL;
            recoverTreeUtil(root, &first, &middle, &last, &prev);
            
            if(first && last)
                swap(first, last);
            else if(first && middle)
                swap(first, middle);
        }
    private:
        void recoverTreeUtil(TreeNode* root, TreeNode** first, 
                             TreeNode** middle, TreeNode** last,
                             TreeNode** prev)
        {
            if(root) {
                recoverTreeUtil(root -> left, first, middle, last, prev);

                if(*prev && root -> val < (*prev) -> val) {
                    if(!*first) {
                        *first = *prev;
                        *middle = root;
                    }
                    else
                        *last = root;
                }
                *prev = root;

                recoverTreeUtil(root -> right, first, middle, last, prev);
            }
        }
        
        void swap(TreeNode* a, TreeNode* b) {
            int tmp = a -> val;
            a -> val = b -> val;
            b -> val = tmp;
        }
};
