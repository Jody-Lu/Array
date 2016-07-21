class Solution(object):
    def reverseList(self, head):
        prev = None
        while head:
            curr = head
            head = head.next
            curr.next = prev
            prev = curr
        
        return prev

    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """

        tmp = head
        n -= m
        
        if n == 0: return head

        prev = None
        
        while m > 1:
            prev = tmp
            tmp = tmp.next
            m -= 1
       
        begin = tmp

        #if not tmp:
        #    return head
        
        while n > 0:
            tmp = tmp.next
            n -= 1
        
        end_next = tmp.next
        tmp.next = None
        rev_list = self.reverseList(begin)
        
        if prev:
            prev.next = rev_list
        else:
            head = rev_list
        
        tmp = rev_list
        while tmp.next:
            tmp = tmp.next

        tmp.next = end_next

        return head
