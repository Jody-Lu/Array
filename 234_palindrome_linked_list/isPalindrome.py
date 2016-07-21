class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        nodes = []
        
        while head:
            nodes.append(head.val)
            head = head.next
        
        nodes_len = len(nodes)

        for idx in range(nodes_len/2):
            if nodes[idx] != nodes[nodes_len - idx - 1]:
                return False
        else:
            return True
