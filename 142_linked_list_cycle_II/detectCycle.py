class Solution(object):
    def detectCycle(self, head):
        slowNode = head
        fastNode = head
        
        while slow and fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                break
        
        if not fast or not fast.next:
            return None


        fast = head
        while slow != fast:
            slow = slow.next
            fast = fast.next

        return slow
