class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head: return head 
        head = self.mergeSort(head)
        return head

    
    def mergeSort(self, head):
        middle = head
        fast = head

        #find middle node
        while fast.next and fast.next.next:
            fast = fast.next.next
            middle = middle.next
        sec = middle.next #if middle.next else head
        middle.next = None

        #if sec != head.next:
        #print middle.val, sec.val
        if head != middle:
            head = self.mergeSort(head)
            sec = self.mergeSort(sec)
        
        head = self.mergeTwoList(head, sec)
        return head
    
    def mergeTwoList(self, List1, List2):
        #print "a", List1.val, List2.val
        tmp_node = ListNode(-1)
        res = tmp_node
        while List1 and List2:
            if List1.val > List2.val:
                tmp_node.next = List2
                List2 = List2.next
            else:
                tmp_node.next = List1
                List1 = List1.next
            
            tmp_node = tmp_node.next

        if List1:
            while List1:
                tmp_node.next = List1
                List1 = List1.next
                tmp_node = tmp_node.next
        
        if List2:
            while List2:
                tmp_node.next = List2
                List2 = List2.next
                tmp_node = tmp_node.next
        
        #print "b", res.next.val, res.next.next.val
        return res.next

                
    def list2linked(self, List):
        res = ListNode(-1)
        tmp = res 
        for item in List:
            tmp.next = ListNode(item)
            tmp = tmp.next
        
        return res.next


if __name__ == '__main__':
    sol = Solution()
    nums = [] 
    node = sol.list2linked(nums)
     
    node = sol.sortList(node)
    
    while node:
        print node.val
        node = node.next
