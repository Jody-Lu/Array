INF = 2 ** 31
class MinStack(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.minimum = INF
        self.elements = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        Every time we push, we have to mainatain
        the self.minimum
        """
        self.minimum = min(self.minimum, x)
        self.elements.append(x)

    def pop(self):
        """
        :rtype: void
        When pop the self.minimum,
        we have to update self.minimum.
        When the stack is empty,
        We have to set self.minimum to INF
        """
        pop = self.elements.pop()
        if self.elements and pop == self.minimum:
            self.minimum = min(self.elements)
        elif not self.elements:
            self.minimum = INF


    def top(self):
        """
        :rtype: int
        """
        return self.elements[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.minimum

minStack = MinStack()
minStack.push(-2)
minStack.push(0)
minStack.push(-3)
print minStack.getMin()
minStack.pop()
print minStack.top()
print minStack.getMin()
