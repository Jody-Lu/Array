##Inorder Traversal

**Why Stack Data Structure:**

Since We have to traverse with the sequence: ``left -> root -> right`` and start with the most left of the tree, the last ``append`` node must be popped first (LIFO), which meets ``stack``'s feature.

**Binary Tree Traversal**

**DFS:**

1. Inorder: left -> root -> right
2. Preorder: root -> left -> right
3. Postorder: left -> right -> root

**BFS**

1. Levelorder 

**How to do so:**

1. ``res`` used to store the results.
2. ``stack`` used to stored the cuurent node been we look.
3. while handling a node, we first ``push`` all its left node into the ``stack`` until its left child is ``None``, then back to its parent and change the root to ``root.right`` (i.e., its right child).   


**Code:**

```python
class Solution(object):
    def inorderTraversal(self, root):
        """
        An iterative version of inorderTraversal.
        """
        res, stack = [], []
        while True:
            while root:
                stack.append(root)
                root = root.left
            if not stack:
                return res
            node = stack.pop()
            res.append(node.val)
            root = node.right
```