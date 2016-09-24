class Solution(object):
    def calculate(self, s):
        s = '(' + s + ')'
        ops = []
        vals = []
        i = 0
        while i < len(s):
            print vals, ops
            if s[i]  == ' ': 
                i += 1
                continue
            elif s[i] in {'+', '-', '('}:
                ops.append(s[i])
            elif s[i] == ')':
                while ops[-1] != '(':
                    op = ops.pop()
                    if op == '+': vals.append(vals.pop() + vals.pop())
                    elif op == '-': vals.append( (-1) * vals.pop() + vals.pop())
                ops.pop()
            else:
                j = i
                while j < len(s) and s[j].isdigit(): j += 1
                vals.append(int(s[i:j]))
                i = j
                continue
            i += 1

        return vals[-1]


sol = Solution()
s = " 2-1 + 2 "
print s
print sol.calculate(s)
    	
