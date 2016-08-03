class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        :type root: TreeNode
        :rtype str
        """
        # If root is None, return empty tree.
        if not root: return "[]"
        curr = [root]
        res = []

        while curr:
            node = curr.pop()
            # If node is not None, put its children into curr
            # either None or something
            if node:
                res.append(str(node.val))
                curr.insert(0, node.left)
                curr.insert(0, node.right)
            # If node is None, put "null" into res
            else:
                res.append("null")

        """
        i = len(res) - 1
        while res[i] == "null":
            i -= 1
        """
        # Since we put all the "null" of deepest node, we have to remove them
        while res[-1] == "null":
            res.pop()
        return  '[' + ','.join(res) + ']'



    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        # Empty tree
        if data == "[]":
            return None
        # Parsing the data into nodes
        nodes = [None if val == "null" else TreeNode(int(val))
                 for val in data.strip("[]").split(',')]

        # kids: used to be popped out
        # nodes: used to construct the tree
        kids = nodes[::-1]
        root = kids.pop()

        for node in nodes:
            if node:
                if kids: node.left = kids.pop()
                if kids: node.right = kids.pop()
        return root




codec = Codec()
data = "[2,1,3,0,7,9,1,2,null,1,0,null,null,8,8,null,null,null,null,7]"
root = codec.deserialize(data)
print data
print codec.serialize(root)








