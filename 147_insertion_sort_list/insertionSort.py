class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def insertionSortList(head):
    res = head
    pre_head = head
    res_head = res
    head = head.next
    prev = None

    while head:
        print "a", head.val
        while res != head and head.val > res.val:
            prev = res
            res = res.next

        if not prev:
            #res.next = head.next
            tmp = res
            while tmp.next != head:
                tmp = tmp.next
            tmp.next = head.next
            tmp = head.next
            head.next = res
            res_head = head
            if not tmp: return res_head
            head = head.next
            
        else:
            prev.next = head
            head.next = res

        res = res_head
        prev = None
        head = head.next

    while res_head:
        print res_head.val
        res_head = res_head.next

def list2linked(List):
    res = ListNode(-1)
    tmp = res
    for item in List:
        tmp.next = ListNode(item)
        tmp = tmp.next

    return res.next



def insertionSort(nums):
    res = []
    res.append(nums[0])
    index = 0
    for item in nums[1:]:
        while index < len(res) and item > res[index]:
            index += 1
        res.insert(index, item)
        index = 0
    return res

if __name__ == '__main__':
    nums = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    head = list2linked(nums)
    head = insertionSortList(head)
    
    while head:
        print head.val
        head = head.next

