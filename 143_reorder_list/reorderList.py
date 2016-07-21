class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseList(self, head):
        prev = None
        while head:
            curr = head
            head = head.next
            curr.next = prev
            prev = curr

        return prev

    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void
        """
        if not head: return 
        fast = head
        middle = head
        while fast.next and fast.next.next:
            middle = middle.next
            fast = fast.next.next
    
        sec = middle.next
        middle.next = None
        sec = self.reverseList(sec)

        tmp = head
        while sec:
            #next_tmp = tmp.next
            next_middle = sec.next
            sec.next = tmp.next#next_tmp
            tmp.next = sec
            tmp = sec.next #next_tmp
            sec = next_middle
    
    def list2linked(self, List):
        res = ListNode(List[0])
        result = res
        for item in List[1:]:
            res.next = ListNode(item)
            res = res.next

        return result


if __name__ == '__main__':
    nums = [1, 2, 3, 4, 5]
    sol = Solution()
    head = sol.list2linked(nums)
    sol.reorderList(head)    
    while head:
        print head.val
        head = head.next
    
