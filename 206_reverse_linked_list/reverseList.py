class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def _reverse(self, node, prev=None):
        if not node:
            return prev
        n = node.next
        node.next = prev
        return self._reverse(n, node)
    
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # v3
        #return self._reverse(head)
        # v2
        prev = None
        while head:
            curr = head
            head = head.next
            curr.next = prev
            prev = curr

        return prev
        # v1
        """
        if not head or not head.next: return head
        if not head.next.next:
            tmp = head
            tmp = tmp.next
            tmp.next = head
            head.next = None
            return tmp

        tmp = head.next
        previous_node = head
        
        while tmp.next:
            this_node = tmp
            next_node = tmp.next
            tmp.next = previous_node
            tmp = next_node
            previous_node = this_node
        head.next = None        
        tmp.next = this_node
        
        return tmp
        """

if __name__ == '__main__':
        nums = [1, 2, 3]
        head = ListNode(0)
        tmp  = head
        for num in nums:
            head.next = ListNode(num)
            head = head.next
                                                
        sol = Solution()
        Node = sol.reverseList(tmp)
        while Node:
            print Node.val
            Node = Node.next



