class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.items = []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.items.insert(0, x)

    def pop(self):
        """
        :rtype: void
        """
        self.items.pop()


    def peek(self):
        """
        :rtype: int
        """
        return self.items[-1]

    def empty(self):
        """
        :rtype: bool
        """
        return not self.items

q = Queue()
q.push(1)
q.push(2)
q.push(3)
q.pop()
print q.peek()
