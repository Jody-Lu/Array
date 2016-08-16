class Solution(object): 
    def fractionToDecimal(self, numerator, denominator):
        '''
        :type numerator: int
        :type denomerator: int
        :rtype str
        '''
        negativeFlag = numerator * denominator < 0
        numerator = abs(numerator)
        denominator = abs(denominator)
        numList = []
        cnt = 0
        loopDict = dict()
        loopStr = None
        while True:
            numList.append(str(numerator/denominator))
            cnt += 1
            numerator = 10 * (numerator % denominator)
            if numerator == 0:
                break
            loc = loopDict.get(numerator)
            if loc:
                loopStr = "".join(numList[loc:cnt])
                break
            loopDict[numerator] = cnt

        ans = numList[0]
        if len(numList) > 1:
            ans += '.'
        if loopStr:
            ans += "".join(numList[1: len(numList) - len(loopStr)]) + "(" + loopStr + ")"

        else:
            ans += "".join(numList[1:])

        if negativeFlag:
            ans = '-' + ans
        return ans


        
if __name__ == '__main__':
    sol = Solution()

    print sol.fractionToDecimal(1, 17)
    """
    print sol.fractionToDecimal(10, 4)
    print sol.fractionToDecimal(1, 2)
    print sol.fractionToDecimal(10, 3)
    print sol.fractionToDecimal(4, 7)
    print sol.fractionToDecimal(2, 3)

    print sol.fractionToDecimal(-7, 12)
    """
