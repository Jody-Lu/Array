class Solution(object):
    def calculate(self, s):
        idx = 0
        res = 0
        sign = [1, 1]

        while idx < len(s):
            x = s[idx]
            if x.isdigit():
                start = idx
                while idx < len(s) and s[idx].isdigit(): idx += 1
                res += sign.pop() * int(s[start:idx])
                continue
            elif x in '(+-':
                # If x == '+', then sign += [1]
                # If x == '-', then sign += [-1]
                sign += [sign[-1] * (1, -1)[x == '-']]
            elif x == ')':
                sign.pop()
            print sign
            idx += 1

        return res


sol = Solution()
s = "(6+8)"
print sol.calculate(s)


