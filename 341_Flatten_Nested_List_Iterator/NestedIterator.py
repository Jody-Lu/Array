# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class NestedIterator(object):
    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        Every NestedInteger is either an integer or a list of NestedInteger.
        Ex: [[1,1], 2, [1,1]]
        print nestedList[0].getList()
        >> [NestedInteger, NestedInteger]
        print nestedList[0].getList()[0].isInteger()
        >> True
        print nestedList[0].getList()[0].getInteger()
        >> 1
        print nestedList[0].getList()[1].isInteger()
        >> True
        print nestedList[0].getList()[0].getInteger()
        >> 1
        """
        """
        flatten all elements when we initialize the object
        """
        self.items = []
        if not nestedList: return 
        curr = [nestedList[0]]
        next = []
        i = 1
        while curr:
            while curr:
                top = curr.pop()
                if top.isInteger():
                    # If next is empty, put all elements into items
                    if not next:
                        self.items.insert(0, top.getInteger())
                    else:
                        next.insert(0, top)
                else:
                    next = top.getList()[::-1] + next

            if i < len(nestedList) and not next:
                next.insert(0, nestedList[i])
                i += 1

            curr, next = next, curr


    def next(self):
        """
        :rtype: int
        """
        val = self.items.pop()
        #print val
        return val

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.items


