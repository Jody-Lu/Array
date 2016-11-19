struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b): start(a), end(b), sum(0), left(NULL), right(NULL) {}
};

class NumMatrix {
public:
    // O(n^2)
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size() != 0) {
            for(int i = 0; i < matrix.size(); i++) {
                int n = matrix[i].size();
                roots.push_back(buildTree(matrix[i], 0, n - 1));
            }
        }
    }

    // O(log(n))
    void update(int row, int col, int val) {
        modifyTree(col, val, roots[row]);
    }
    
    // O(nlog(n))
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int i = row1; i <= row2; i++) {
            res += queryTree(col1, col2, roots[i]);
        }
        return res;
    }
    
    // O(n) -- n = nums.size()
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
    // O(lg(n))
    int modifyTree(int i, int val, SegmentTreeNode* root) {
        if(!root) { return 0; }
        int diff;

        if(root->start == i && root->end == i) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }

        int mid = (root->start + root->end) / 2;

        if(i > mid) {
            diff = modifyTree(i, val, root->right);
        }
        else {
            diff = modifyTree(i, val, root->left);
        }

        root->sum += diff;
        return diff;
    }

    // O(n)
    int queryTree(int i, int j, SegmentTreeNode* root) {
        if(!root) { return 0; }
        if(root->start == i && root->end == j) {
            return root->sum;
        }

        int mid = (root->start + root->end) / 2;
        if(i > mid) {
            return queryTree(i, j, root->right);
        }
        if(j <= mid) {
            return queryTree(i, j, root->left);
        }
        return queryTree(i, mid, root->left) + queryTree(mid + 1, j, root->right);
    }

private:
    vector<SegmentTreeNode*> roots;
};

