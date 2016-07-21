class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def insertionSortList_v2(self, head):
        p = dummy = ListNode(0)
        cur = dummy.next = head
        print"c", cur.val
        while cur and cur.next:
            val = cur.next.val
            print "d", cur.val
            print "val", val
            if cur.val < val:
                cur = cur.next
                continue
            if p.val > val:
                p = dummy
            while p.next.val < val:
                p = p.next
            print "p", p.val
            new = cur.next
            cur.next = new.next
            new.next = p.next
            p.next = new
        return head
        #return dummy.next
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        res = ListNode(head.val)
        res_head = res
        head = head.next
        prev = None
        #print head.val
        
        while head:
            while res and head.val > res.val:
                prev = res
                res = res.next
            # insert at the head
            if not prev:
                prev = ListNode(head.val)
                prev.next = res_head
                res_head = prev
            # insert at the end    
            elif not res:
                prev.next = ListNode(head.val)
            # insert at the middle
            else:
                prev.next = ListNode(head.val)
                prev.next.next = res
            # reset
            res = res_head
            prev = None
            head = head.next

        return res_head

    def list2linked(self, List):
        res = ListNode(-1)
        tmp = res 
        for item in List:
            tmp.next = ListNode(item)
            tmp = tmp.next
        
        return res.next

if __name__ == '__main__':
    sol = Solution()
    nums = [5, 1, 6, 3]
    head = sol.list2linked(nums)
    res = sol.insertionSortList_v2(head)
    
    while res:
        print res.val
        res = res.next


