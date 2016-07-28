import collections

class Stack(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = collections.deque()

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.queue.append(x)


    def pop(self):
        """
        :rtype: void
        """
        self.queue.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.queue[-1]

    def empty(self):
        """
        :rtype: bool
        """
        return not self.queue

stack = Stack()
stack.push(1)
stack.push(2)
stack.push(3)
stack.pop()
print stack.empty()

