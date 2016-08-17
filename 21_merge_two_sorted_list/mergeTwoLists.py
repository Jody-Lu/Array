class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1: return l2
        elif not l2: return l1

        res = ListNode(-1)
        result = res
        while l1 and l2:
            if l2.val > l1.val:
                res.next = l1
                l1 = l1.next
            else:
                res.next = l2
                l2 = l2.next
        if(l1): res.next = l1
        if(l2): res.next = l2

        return result.next
