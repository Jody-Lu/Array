# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):

    def __init__(self, head):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        :type head: ListNode
        """
        self.items = []
        while head:
            self.items.append(head.val)
            head = head.next
        self.n = len(self.items)

    def getRandom(self):
        """
        Returns a random node's value.
        :rtype: int
        """
        from random import randint
        return self.items[randint(0, self.n - 1)]
