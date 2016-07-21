class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        result = []
        def dfs(input):
            if input.isdigit(): 
                #print input
                return int(input)
            
            for idx in range(len(input)):
                if not input[idx].isdigit():
                    #print input[idx], input[:idx], input[idx + 1:]
                    if input[idx] == '+':
                        return dfs(input[:idx]) + dfs(input[idx + 1:])
                    elif input[idx] == '-':
                        print "a", str(dfs(input[:idx]) - dfs(input[idx + 1:]))
                        return dfs(input[:idx]) - dfs(input[idx + 1:])
                    elif input[idx] == '*':
                        return dfs(input[:idx]) * dfs(input[idx + 1:])
        print dfs(input)

sol = Solution()
input = "2-1-1-3+5"
sol.diffWaysToCompute(input)
        


