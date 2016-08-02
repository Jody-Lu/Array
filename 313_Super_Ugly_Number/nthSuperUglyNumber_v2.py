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
                print nums
                print index
                # Find the minimum and go forward
                if nums[j] == curr:
                    nums[j] = best[index[j]] * primes[j]
                    index[j] += 1
                print nums[j]
            curr = min(nums)
            print "curr: ", curr
            best.append(curr)

        return best[-1]

sol = Solution()
n = 5
primes = [2, 3, 5]
print sol.nthSuperUglyNumber(n, primes)


