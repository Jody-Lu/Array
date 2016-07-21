# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        root = self.dfs(head)
        return root

    def dfs(self, start):
        if not start: return None        
        #if start == end: return TreeNode(start.val)

        prev_slow = None # the node that one node before the slow
        slow = start # move one nodes each time
        fast = start # move two nodes each time

        # slow node will stop at middle (root node)
        while fast.next and fast.next.next:
            prev_slow = slow
            fast = fast.next.next
            slow = slow.next
        
        # slow is the root at this level
        tree_node = TreeNode(slow.val)

        # using slow as pivot, dividing the linked list
        # into two sub-list (:pre_slow), (slow.next:)
        if prev_slow:
            prev_slow.next = None
            tree_node.left = self.dfs(start)
        
        if slow.next:
            tree_node.right = self.dfs(slow.next)

        return tree_node

