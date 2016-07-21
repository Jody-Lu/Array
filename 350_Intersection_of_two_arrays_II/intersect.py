class Solution(object):
    def intersect(self, num1, num2):
        hash_map = {}
        res = []
        
        for n in num1:
            if hash_map.has_key(n):
                hash_map[n] += 1
            else:
                hash_map[n] = 1
        
        for n in num2:
            if hash_map.has_key(n):
                if hash_map[n] > 0:
                    res.append(n)
                    hash_map[n] -= 1
                else:
                    continue
        return res

sol = Solution()
num1 = [1, 2, 2, 1, 3, 3, 3, 4]
num2 = [2, 2, 3, 3, 4, 4, 4]
print sol.intersect(num1, num2)
