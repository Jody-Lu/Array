class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        result = res = ListNode(-1)
        while l1 and l2:
            if l2.val > l1.val:
                res.next = l1
                l1 = l1.next
            else:
                res.next = l2
                l2 = l2.next
            res = res.next

        res.next = l1 or l2
        return result.next
    
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        """
        if not lists: return None
        
        first = 0
        last = len(lists) - 1
        middle = (first + last) / 2
        
        if len(lists) > 2:
            l1 = self.mergeKLists(lists[:middle+1])
            l2 = self.mergeKLists(lists[middle+1:])

        elif len(lists) == 2:
            l1 = lists[0]
            l2 = lists[1]

        else: return lists[0]

        res = self.mergeTwoLists(l1, l2)
        
        return res
if __name__ == '__main__':
    l1 = ListNode(1)
    l2 = ListNode(2)
    sol = Solution()
    node = sol.mergeTwoLists(l1, l2)
    while node:
        print node.val
        node = node.next
