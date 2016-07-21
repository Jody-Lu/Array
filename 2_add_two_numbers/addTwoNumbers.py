class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def getListLength(self, head):
        cnt = 0
        tmp = head
        while tmp:
            cnt += 1
            tmp = tmp.next
        return cnt
    
    def add_zero(self, head, diff):
        tmp = head
        
        while tmp.next:
            tmp = tmp.next
        
        while diff != 0:
            tmp.next = ListNode(0)
            tmp = tmp.next
            diff -= 1
        
        return head
    
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        diff = self.getListLength(l1) - self.getListLength(l2)
        carrier = 0
        
        if diff > 0:
            l2 = self.add_zero(l2, diff)
        elif diff < 0:
            l1 = self.add_zero(l1, abs(diff))
        
        head = l1
        
        prev = None 
        
        while l1:
            prev = l1
            val = l1.val + l2.val + carrier
            
            if val >= 10:
                l1.val = val - 10
                carrier = 1
            else:
                l1.val = val
                carrier = 0

            l1 = l1.next
            l2 = l2.next

        if carrier >= 1:
            if not prev.next:
                prev.next = ListNode(carrier)
            else:
                prev.next.val += carrier
        
        return head

if __name__ == '__main__': 
    l1 = ListNode(9)
    l2 = ListNode(2)

    sol = Solution()
    
    head = sol.addTwoNumbers(l1, l2)
    print sol.getListLength(head)
    print head.next.val
    


