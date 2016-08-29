class Solution(object):
    def combinationSum(self, candidates, target):
        result = []
        # If we sort the list, onece we meet an item greater
        # than current remain, we know the remains of the list
        # would larger than the remain. So, we break the for loop.
        candidates = sorted(candidates)
        
        def dfs(remain, stack):
            if not remain:
                result.append(stack)
                return 

            for item in candidates:
                if item > remain: break
                # To avoid duplicate result, we have to avoid push
                # the item that is smaller than the last item of the stack
                # With this if condition, we can get non-duplicated stacks 
                # with increasing order. 
                if stack and item < stack[-1]: continue
                else:
                    dfs(remain - item, stack + [item])
        
        dfs(target, [])
        return result


candidates = [2, 3, 6, 7]
target = 100
sol = Solution()
res = sol.combinationSum(candidates, target)
print res
