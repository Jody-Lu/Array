#include <string>
#include <list>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "[]";
        list<TreeNode*> curr;
        string res = "[";
        while(!curr.empty()) {
            TreeNode* node = curr.top();
            curr.pop_back();
            if(node) {
                res.push_back(to_string(node->val) + ",");
                curr.push_front(node->left);
                curr.push_front(node->right);
            }
            else
                res.push_back("null,");
        }
        res.pop_back();
        return res + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "[]") return NULL;

    }
};
