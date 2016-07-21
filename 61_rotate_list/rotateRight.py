# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getListLength(self, head):
        cnt = 0
        while head:
            head = head.next
            cnt += 1
        return cnt
        
    def rotateRight(self, head, k):
        length = self.getListLength(head)
        if not head or k == 0: return head
        
        if k > length: k = k % length
        walk_length = length - k
        
        if walk_length == 0 or k == 0: return head
        print walk_length
        
        tmp = head
        while walk_length != 0:
            prev = tmp
            tmp = tmp.next
            walk_length -= 1

        r_head = tmp
        
        while tmp and tmp.next:
            tmp = tmp.next

        tmp.next = head
        prev.next = None

        return r_head


        
