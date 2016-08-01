from heapq import heappush, heappop, heapreplace, heapify
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        Heap
        """
        # dummy and node point to the same memory space
        # node is used to operate
        dummy = node = ListNode(0)
        # put all head node of lists into heap
        h = [(n.val, n) for n in lists if n]
        heapify(h)

        while h:
            v, n = h[0]
            # If n has no next, pop it and contunue with next linked list
            if n.next is None:
                heappop(h)
            else:
                heapreplace(h, (n.next.val, n.next))
            node.next = n
            node = node.next

        return dummy.next


