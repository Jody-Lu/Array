#Find Lowest Common Ancestor (LCA)

##Binary Search Tree

**Algorithm**

1. According to the feature of ``BST``: A root's left child's value must be smaller than root's val; a root's right child's value must be bigger than root's val.
2. ``(root.val - p.val) * (root.val - q.val)`` > 0, which means that both ``p`` and ``q`` are in the same subtree, and their LCA must be in this subtree.
3. ``(root.val - p.val) * (root.val - q.val)`` == 0, which means that either ``p`` or ``q`` equals to root, which is their LCA.
4. ``(root.val - p.val) * (root.val - q.val)`` < 0, which means ``p`` and ``q`` belongs to different subtrees and ``root`` is their LCA.

**Code**

```python

```      

##Binary Tree
