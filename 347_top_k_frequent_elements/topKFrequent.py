class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype List[int]
        """
        Result = []
        num_dic = {}
        for num in nums:
            if num_dic.has_key(num):
                num_dic[num] += 1
            else:
                num_dic[num] = 1
        numList = sorted(num_dic.items(), key=lambda x: x[1])
        numList.reverse()

        Result = [item[0] for item in numList[0:k]]

        return sorted(Result)

if __name__ == '__main__':
    sol = Solution()
    nums = [1,1,1,2,2,2,3,3,4]
    k = 3
    print sol.topKFrequent(nums, k)
