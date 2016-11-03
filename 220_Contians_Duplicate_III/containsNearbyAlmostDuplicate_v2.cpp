#include <iostream>

using namespace std;


template<class T>
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T x): val(x), left(NULL), right(NULL) {}
};


template<class T>
class BST {
    public:
        BST(): _root(NULL) {}
        ~BST() {}
        
        void insert(T x) {
            if(_root != NULL) {
                insertHelper(this->_root, x);
            }
            else { // tree doesn't create yet
                _root = new TreeNode<T>(x);
            }
        }

        TreeNode<T>* search(T x) {
            return searchHelper(this->_root, x);
        }

        void print() {
            printHelper(this->_root);
        }

        int nodesCount() {
            return nodesCountHelper(this->_root);
        }

        int height() {
            return heightHelper(this->_root);
        }

        bool deleteValue(T value) {
            return deleteValueHelper(NULL, this->_root, value);
        }
    
    private:

        TreeNode<T>* _root;

        void insertHelper(TreeNode<T>* root, T x) {
            if(x > root->val) {
                if(!root->right) {
                    root->right = new TreeNode<T>(x);
                }
                else {
                    insertHelper(root->right, x);
                }
            }
            else {
                if(!root->left) {
                    root->left = new TreeNode<T>(x);
                }
                else {
                    insertHelper(root->left, x);
                }
            }
        }

        TreeNode<T>* searchHelper(TreeNode<T>* root, T x) {
            if(root == NULL || root->val == x) {
                return root;
            }

            if(x > root->val) {
                return searchHelper(root->right, x);
            }
            else {
                return searchHelper(root->left, x);
            }
        }

        void printHelper(TreeNode<T>* root) {
            // inorder traversal
            if(!root) { return; }

            printHelper(root->left);
            cout << root-> val << " ";
            printHelper(root->right); 
        } 

        int nodesCountHelper(TreeNode<T>* root) {
            return (root)? (1 + nodesCountHelper(root->left) + nodesCountHelper(root->right)) : 0;
        }

        int heightHelper(TreeNode<T>* root) {
            return (root)? (1 + max(heightHelper(root->left), heightHelper(root->right))) : 0;
        }

        bool deleteValueHelper(TreeNode<T>* parent, TreeNode<T>* current, T value) {
            if(!current) { return false; }
            if(current->val == value) {
                // one child
                if(!(current->left) || !(current->right)) {
                    TreeNode<T>* tmp = current->left;
                    if(current->right) { tmp = current->right; }
                    if(parent) {
                        if(parent->left == current) {
                            parent->left = tmp;
                        }
                        else {
                            parent->right = tmp;
                        }
                    }
                    else {
                        this->_root = tmp;
                    }
                }
                else { // double child
                    TreeNode<T>* validSubs = current->right;
                    while(validSubs->left) {
                        validSubs = validSubs->left;
                    }
                    T tmp = current->val;
                    current->val = validSubs->val;
                    validSubs->val = tmp;
                    return deleteValueHelper(current, current->right, tmp);
                }
                delete current;
                return true;
            }
            return deleteValueHelper(current, current->left, value) ||
                   deleteValueHelper(current, current->right, value);  
        }

};

int main() {
    BST<int> bst;
    bst.insert(10);
     //BST<int>* bst = new BST<int>();
     //bst->insert(10);
    bst.deleteValue(10);
    return 0;
}
