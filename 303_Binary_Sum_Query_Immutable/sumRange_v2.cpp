struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b): start(a), end(b), left(NULL), right(NULL) {}
};

class NumArray {
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        root = buildTree(nums, 0, n - 1);
    }

    int sumRange(int i, int j) {
        return queryTree(i, j, root);
    }

    SegmentTreeNode* buildTree(vector<int>& nums, int start, int end) {
        if(start > end) { return NULL; }
        SegmentTreeNode* root = new SegmentTreeNode(start, end);

        if(start == end) {
            root->sum = nums[start];
            return root;
        }

        int mid = start + (end - start) / 2;

        root->left = buildTree(nums, start, mid);
        root->right = buildTree(nums, mid + 1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    int queryTree(int i, int j, SegmentTreeNode* root) {
        if(!root) { return 0; }
        if(i == root->start && j == root->end) { return root->sum; }
        int mid = (root->start + root->end) / 2;
        if(j <= mid) { return queryTree(i, j, root->left); }
        if(i > mid) { return queryTree(i, j, root->right); }
        return queryTree(i, mid, root->left) + queryTree(mid + 1, j, root->right);
    }

private:
    SegmentTreeNode* root;
};
