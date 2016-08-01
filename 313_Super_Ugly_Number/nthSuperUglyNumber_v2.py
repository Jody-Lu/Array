class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        """
        nums = [1] * len(primes)
        index = [0] * len(primes)
        best = [1]
        curr = 1
        for i in xrange(n - 1):
            for j in xrange(len(index)):
                if nums[j] == curr:
                    nums[j] = best[index[j]] * primes[j]
                    index[j] += 1
            curr = min(nums)
            best.append(curr)

        return best[-1]




