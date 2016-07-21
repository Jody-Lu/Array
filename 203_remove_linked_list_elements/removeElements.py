class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        tmp = head
        prev = None
        
        while tmp:
            if tmp.val == val:
                if prev == None:
                    head = head.next
                else:
                    prev.next = tmp.next
            else:
                prev = tmp
            
            tmp = tmp.next


        return head

