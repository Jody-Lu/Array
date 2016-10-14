class Solution(object):
    def isValidSerialization(self, preorder):
        p = preorder.split(',')
        nullCnt = 0
        nodeCnt = 0
        n = len(p)

        for idx in n:
            if p[idx] == '#':
                nullCnt += 1
            else:
                nodeCnt += 1

            if nullCnt == nodeCnt + 1 and idx != n - 1:
                return False

        return nullCnt == nodeCnt + 1
