class Solution(object):
    def deserialize(self, s):
        """
        :type s: str
        :rtype: NestedInteger
        """
        def nestedInteger():
            num = ''
            while s[-1] in '123456789-':
                num += s.top()

            if num:
                return NestedInteger(int(num))
            s.pop()
            lst = NestedInteger()
            while s[-1] != ']':
                lst.add(nestedInteger())
                if s[-1] == ',':
                    s.pop()
            s.pop()
            return lst
        s = list(' ' + s[::-1])
        return nestedInteger()




