import operator

class Solution(object):
    cache = {}
    ops = {"+":operator.add, "-":operator.sub, "*":operator.mul}
    def diffWaysToCompute(self, input):
        ans = []
        for idx in xrange(len(input)):
            oper = input[idx]
            if oper in {'+', '-', '*'}:
                left = self.diffWaysToCompute(input[:idx])
                right = self.diffWaysToCompute(input[idx+1:])

                for l in left:
                    for r in right:
                        ans.append(self.ops[oper](l, r))
                self.cache[input[:idx] + oper + input[idx+1:]] = ans
        if not ans: # meet only digit
            ans.append(int(input))
        return ans

sol = Solution()
input = "2*3-4*5"
print sol.diffWaysToCompute(input)
print sol.cache
