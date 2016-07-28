class Queue(object):
    def __init__(self):
        self.items = []

    def isEmpty(self):
        """
        :rtype: bool
        """
        return not self.items
    
    def enqueue(self, item):
        """
        :type item: int
        :rtype: void
        """
        self.items.insert(0, item)

    def dequeue(self):
        """
        pop an item out.
        """
        self.items.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.items[-1]
    
    def dump(self):
        return self.items
    
    def size(self):
        """
        :rtype: int
        """
        return len(self.items)


q = Queue()
print q.isEmpty()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
print q.dump()

