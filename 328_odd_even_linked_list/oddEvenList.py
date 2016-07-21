# Definition for single linked list
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head: return None
        tmp = head
        even = tmp.next
        cnt = 1 
        
        while tmp.next:
            this_node = tmp
            next_node = tmp.next
            tmp.next = next_node.next
            tmp = next_node
            cnt += 1
        
        
        if cnt % 2 == 1:
            tmp.next = even
            return head
        else:
            this_node.next = even
            return head

        """
        tmp = head 
        while tmp.next:
            tmp = tmp.next

        tmp.next = even
        return head
        """
        #while head:
        #    print head.val
        #    head = head.next

            

if __name__ == '__main__':
    nums = [1, 2, 3, 4, 5]
    head = ListNode(0)
    tmp  = head
    for num in nums:
        head.next = ListNode(num)
        head = head.next
    
    sol = Solution()
    sol.oddEvenList(tmp)
    while tmp:
        print tmp.val
        tmp = tmp.next

