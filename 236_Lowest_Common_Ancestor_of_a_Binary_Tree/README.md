#Find Lowest Common Ancestor (LCA)

##Binary Search Tree

**Algorithm**

1. According to the feature of ``BST``: A root's left child's value must be smaller than root's val; a root's right child's value must be bigger than root's val.
2. ``(root.val - p.val) * (root.val - q.val)`` > 0, which means that both ``p`` and ``q`` are in the same subtree, and their LCA must be in this subtree.
3. ``(root.val - p.val) * (root.val - q.val)`` == 0, which means that either ``p`` or ``q`` equals to root, which is their LCA.
4. ``(root.val - p.val) * (root.val - q.val)`` < 0, which means ``p`` and ``q`` belongs to different subtrees and ``root`` is their LCA.

**Code**

```python
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        while (root.val - p.val) * (root.val - q.val) > 0:
            root = (root.left, root.right)[p.val > root.val]
        return root
```      

##Binary Tree

**Algorithm 1**

1. Since we don't have BST's feature, we have to come up other method.
2. We find ``path_p`` and ``path_q`` (Note: We cannot match two nodes by their value, since we may have duplicated node).
3. Comparing the ``path_p`` and ``path_q``, and finding the last common node. 

**Code (Method 1)**

```python
class Solution(object):
    def findPath(self, root, path, k):
        if not root: 
            return False
        path.append(root)

        if root == k:
            return True
        if ((root.left and self.findPath(root.left, path, k)) or 
                (root.right and self.findPath(root.right, path, k))):
            return True
        path.pop()
        return False

    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        path_p = []
        path_q = []

        if (not self.findPath(root, path_p, p)) or (not self.findPath(root, path_q, q)):
                return -1

        i = 0
        while i < len(path_p) and i < len(path_q):
            if path_p[i].val != path_q[i].val:
                break
            i += 1
        return path_p[i - 1]
```

**Algorithm 2**

The method 1 finds LCA in O(n) time, but requires three tree traversals plus extra spaces for path arrays. If we assume that the keys n1 and n2 are present in Binary Tree, we can find LCA using single traversal of Binary Tree and without extra storage for path arrays.
The idea is to traverse the tree starting from root. If any of the given keys (n1 and n2) matches with root, then root is LCA (assuming that both keys are present). If root doesn’t match with any of the keys, we recur for left and right subtree. The node which has one key present in its left subtree and the other key present in right subtree is the LCA. If both keys lie in left subtree, then left subtree has LCA also, otherwise LCA lies in right subtree.

**Code (Method 2)**

```python
class Solution(object):
    def lowestCommonAncestor(self, root, p , q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return None

        if root == p or root == q:
            return root

        left_lca = self.lowestCommonAncestor(root.left, p, q)
        right_lca = self.lowestCommonAncestor(root.right, p, q)

        if left_lca and right_lca:
            return root

        return left_lca if left_lca else right_lca
```