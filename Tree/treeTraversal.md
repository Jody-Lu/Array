##Tree Traversal

**Inorder Traversal**

Sequence: ``left -> root -> right``

*Recursive:*

```python
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        stack = []
        def dfs(root):
            if not root: return
            if root.left: dfs(root.left)
            stack.append(root.val)
            if root.right: dfs(root.right)
        dfs(root)
        return stack
```

*Iterative:*

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

**Preorder Traversal**

Sequence: ``root -> left -> right``

*Recursive:*

```python
class Solution(object):
    result = []
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.traverse(root)
        return result

    def traverse(self, root):
        if not root: return

        result.append(root.val)
        traverse(root.left)
        traverse(root.right)
```

*Iterative:*

```python
class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        Iterative version

        """
        traversal, stack = [], [(root, False)]
        while stack:
            node, visited = stack.pop()
            if node:
                if visited:
                    traversal.append(node.val)
                else:
                    stack.append((node.right, False))
                    stack.append((node.left, False))
                    stack.append((node, True))

        return traversal
```

**Postorder Traversal**

Sequence: ``left -> right -> root``

*Recursive:*

```python
class Solution(object):
    def postorderTraversal(self, root):
        result = []
        def traverse(root):
            if not root: return
            traverse(root.left)
            traverse(root.right)
            result.append(root.val)

        traverse(root)
        return result
```

*Iterative:*

```python
class Solution(object):
    def postorderTraversal(self, root):
        """
        Iterative version
        """
        traversal, stack = [], [(root, False)]
        while stack:
            node, visited = stack.pop()
            if node:
                if visited:
                    traversal.append(node.val)
                else:
                    stack.append((node, True))
                    stack.append((node.right, False))
                    stack.append((node.left, False))

        return traversal
```
