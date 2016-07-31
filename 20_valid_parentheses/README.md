##Valid Parentheses
**Consideration:**

1. If ``len(s)`` is odd, ``s`` must not be a valid parentheses string.
2. ``stack``, which is used to store the parentheses.
3. ``para_dic``, which is used to store the mapping between right and left parenthese.
4. We survey string ``s``. If we meet left parentheses, we push them into the ``stack``. If we meet the right parentheses, we pop the left parenthese from the ``stack``.
5. If ``stack`` is empty or the right parenthese we meet is not paired with the left one, return ``False``.
6. Upon end of survey, if ``len(stack) == 0``, which means all parentheses are paired, return ``True``, else return ``False``.

**Why Used Stack Data Structure**

1. The last pushed parenthese must be paired and popped first, which meets the feature of stack: Last In First Out (LIFO).


**Source Code:**

```python
class Solution(object):
    def isValid(self, s):
        if len(s) % 2 == 1: return False
        stack = []
        para_dic = {')':'(', ']':'[', '}':'{'}
        for idx in xrange(len(s)):
            if s[idx] in {'(', '[', '{'}: 
                stack.append(s[idx])
            else:
                if not len(stack) or para_dic[s[idx]] != stack[-1]: return False
                else: stack.pop()

        
        return len(stack) == 0
```