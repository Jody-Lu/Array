class Solution(object):
    def hasCycle(self, head):
        showNode = head
        fastNode = head
        
        while showNode and fastNode and fastNode.next:
            showNode = showNode.next
            fastNode = fastNode.next

            if showNode == fastNode:
                return True

        return False
