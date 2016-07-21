class Solution(object):
    def calculate(self, s):
        res = 0
        idx = 0
        sign = ['+', '+']
        nums = []

        while idx < len(s):
            x = s[idx]
            if x.isdigit():
                start = idx
                while idx < len(s) and s[idx].isdigit(): idx += 1
                top_sign = sign.pop()
                if top_sign == '+':
                    nums.append(int(s[start:idx]))
                elif top_sign == '-':
                    nums.append(int(s[start:idx]) * (-1))
                elif top_sign == '*':
                    nums[-1] *= int(s[start:idx])
                elif top_sign == '/':
                    sig = (nums[-1]/abs(nums[-1])) if nums[-1] != 0 else 1
                    nums[-1] = abs(nums[-1]) / int(s[start:idx]) * sig
                continue
            elif x in '*/+-':
                sign.append(s[idx])

            idx += 1


        return sum(nums)

sol = Solution()
s = "0/1"
print s
print sol.calculate(s)
