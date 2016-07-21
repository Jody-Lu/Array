class Solution(object):
    def deleteDuplicates(self, head):

        count = 1
        while head and head.next and:
            if head.val == head.next.val:
                head = head.next
                count += 1
        
        if count > 1:
            head = head.next
        
        tmp = head
        prev = None


        
        
        while tmp and tmp.next:
            if tmp.val == tmp.next.val:
                if tmp.next.next:
                    tmp.next = tmp.next.next
                else:
                    prev.next = None
            else:
                if prev == None:
                    head = tmp.next
                prev = tmp
                tmp = tmp.next


        
        return head

