import time
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def partition(self, head, x):
        smaller_head = tmp_small = ListNode(-1)
        larger_head = tmp_large  = ListNode(-1)

        while head:
            if head.val < x:
                tmp_small.next = head
                tmp_small = tmp_small.next
            else:
                tmp_large.next = head
                tmp_large = tmp_large.next
            head = head.next

        tmp_large.next = None
        tmp_small.next = larger_head.next   
        #smaller_head = smaller_head.next
        
        return smaller_head.next
    
    def list2linked(self, nums):
        res = ListNode(nums[0])
        tmp = res
        for item in nums[1:]:
            tmp.next = ListNode(item)
            tmp = tmp.next
        return res

if __name__ == '__main__':
    tmp_list1 = []
    tmp_list2 = []
    x = 70000
    for i in range(x):
        tmp_list1.append(i)
        tmp_list2.append(x + i)

    nums = tmp_list2 + tmp_list1
    
    sol = Solution()
    head = sol.list2linked(nums)
    
    start_time = time.time()
    head = sol.partition(head, x)
    print "--- %s ms ---" % ((time.time() - start_time) * 1000)
    
    """
    while head:
        print head.val
        head = head.next
    """
