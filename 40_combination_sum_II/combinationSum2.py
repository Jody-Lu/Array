class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype List[List[int]]
        """
        candidates = sorted(candidates)
        result = []
        
        def dfs(stack, remain, start):
            if remain == 0 and stack not in result:
                result.append(stack)
            
            for idx, item in enumerate(candidates[start:]):
                if remain < item: return
                #if item in candidates[0: start]: continue
                dfs(stack + [item], remain - item, start + idx + 1)          

        dfs([], target, 0)

        return result

if __name__ == '__main__':
    sol = Solution()
    candidates = [10, 1, 2, 7, 6, 1, 5]
    target = 8
    print sol.combinationSum2(candidates, target)
