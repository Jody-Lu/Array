/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > verticalOrder(TreeNode* root) {
        map<int, vector<int> > m;
        vector<vector<int> > res;

        if(!root) { return res; }

        list<pair<int, TreeNode*> > q;
        q.push_front(make_pair(0, root));

        while(!q.empty()) {
            pair<int, TreeNode*> curr = q.back();
            q.pop_back();
            m[curr.first].push_back((curr.second)->val);
            if((curr.second)->left) {
                q.push_front(make_pair(curr.first - 1, (curr.second)->left));
            }
            if((curr.second)->right) {
                q.push_front(make_pair(curr.first + 1, (curr.second)->right));
            }
        }

        for(auto it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }

        return res;

    }
};