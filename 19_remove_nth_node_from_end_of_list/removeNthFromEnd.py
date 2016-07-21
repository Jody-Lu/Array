class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def getListLength(self, head):
        tmp = head
        cnt = 0
        while tmp:
            cnt += 1
            tmp = tmp.next
        return cnt

    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtypr: ListNode
        """
        length = self.getListLength(head)
        target = length - n + 1
        if target == 1: return head.next

        #print length, target
        tmp = head
        while target > 2:
            tmp = tmp.next
            target -= 1

        tmp.next = None if not tmp.next.next else tmp.next.next

        return head

if __name__ == '__main__':
    head = ListNode(1)
    #tmp = head
    #tmp.next = ListNode(2)
    #tmp.next.next = ListNode(3)
    n = 1
    
    sol = Solution()
    res = sol.removeNthFromEnd(head, n)
    
    while res:
        print res.val
        res = res.next
