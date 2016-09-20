def hammingWeight(n):
        if n == 0: return 0
        else:
            return hammingWeight(n / 2) + (n % 2)


class Solution(object):
    def __init__(self):
        def help1():
            h1 = ['8', '4', '2', '1'] # <= 3; == 3
            h1.sort()
            h2 = ['3', '5', '9', '6', '10']
            h2.sort()
            h3 = ['7', '11']
            h3.sort()
            m1 = ['32', '16', '08', '04', '02', '01']
            m1.sort()

            m2 = []
            for i in xrange(3,49):
                if hammingWeight(i) == 2: 
                    if i >= 10: m2.append(str(i))
                    elif i < 10: m2.append('0' + str(i))

            m3 = []
            for i in xrange(7, 57):
                if hammingWeight(i) == 3:
                    if i >= 10: m3.append(str(i))
                    elif i < 10: m3.append('0' + str(i))
            m4 = [] # 15 ~ 60
            self.hours = [h1, h2, h3]
            for i in xrange(15, 60):
                if hammingWeight(i) == 4: m4.append(str(i))
            m5 = [] # 31 ~ 59
            for i in xrange(31, 60):
                if hammingWeight(i) == 5: m5.append(str(i))

            self.mins = [m1, m2, m3, m4, m5]
        help1()
    res = []

    def readBinaryWatch(self, n):
        if n > 8: return self.res
        if n == 0: return ["0:00"]
        # a: h, b: m
        res = []

        def help(a, b):

            if a == 0 and b == 0: return

            if a == 0:
                for i in xrange(len(self.mins[b - 1])):
                    res.append("0:" + self.mins[b - 1][i])
                return

            if b == 0:
                for i in xrange(len(self.hours[a - 1])):
                    res.append(self.hours[a - 1][i] + ":00")
                return

            for i in xrange(len(self.hours[a - 1])):
                for j in xrange(len(self.mins[b - 1])):
                    res.append(self.hours[a - 1][i] + ":" + self.mins[b - 1][j])
            return

        for i in xrange(n + 1):
            a = i
            b = n - i
            if a > 3 or b > 5: continue
            else: help(a, b)

        return res