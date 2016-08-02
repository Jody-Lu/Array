class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        :Take all gas from each station
        :Start from the most gas station
        """
        # If sum(gas) > sum(cost), we must can complete the circuit
        if not len(gas) or not len(cost) or sum(gas) < sum(cost):
            return -1
        position = 0
        balance = 0
        for i in xrange(len(gas)):
            balance += gas[i] - cost[i]
            if balance < 0:
                balance = 0
                position = i + 1
        return position
sol = Solution()
gas = [1, 2, 3, 3]
cost = [2, 1, 5, 1]
print sol.canCompleteCircuit(gas, cost)


