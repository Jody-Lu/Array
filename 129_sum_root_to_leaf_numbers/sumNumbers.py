class Solution(object):
    # version 3 -- Iteration Version -- Breadth First Search (BFS)
    def sumNumbers(self, root):
        total = 0
        q = []
        sumq = []
        if root:
            q.append(root)
            sumq.append(root.val)
        while q:
            curr = q.pop()
            partial_sum = sumq.pop()
            if not curr.left and not curr.right:
                total += partial_sum
            else:
                if curr.right:
                    q.append(curr.right)
                    sumq.append(partial_sum * 10 + curr.right.val)
                if curr.left:
                    q.append(curr.left)
                    sumq.append(partial_sum * 10 + curr.left.val)
        return total



    # version 2 -- Recursive Version -- Depth First Search Version (DFS)
    """
    def sumNumbers(self, root):
        def sumR(root, x):
            if not root.left and not root.right:
                return 10 * x + root.val
            val = 0
            if root.left:
                val += sumR(root.left, 10 * x + root.val)
            if root.right:
                val += sumR(root.right, 10 * x + root.val)

            return val
        if not root: return 0
        else: return sumR(root, 0)
    """
    # version 1
    """
    def sumNumbers(self, root):
        paths = []
        def dfs(root, path):
            if not root: return 
            if not root.left and not root.right:
                paths.append(path + [root.val])
            
            dfs(root.left, path + [root.val])
            dfs(root.right, path+ [root.val])

        dfs(root, [])
        sum = 0
        for path in paths:
            power = len(path) - 1
            num= 0
            for item in path:
                num += item * (10 ** power)
                power -= 1
            sum += num
        
        return sum
    """
