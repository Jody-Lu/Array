class Solution(object):
    def countFirstOne(self, bi):
        count = 0
        while(count < len(bi) and bi[count] == '1'):
            count += 1
        return count

    def validUtf8(self, data):
        bis = []
        n = len(data)
        # Transform each data into 8-bits binary
        for d in data:
            bi = bin(d)[2:]
            l = len(bi)
            if(l > 8):
                bis.append(bi[l-8:])
            else:
                bis.append('0' * (8 - l) + bi)

        print bis
        idx = 0
        while idx < n:
            # every time comes here is a new character
            count = self.countFirstOne(bis[idx])
            if count == 1: return False # no UTF8 with only one.
            if count == 0: # 1-byte character
                idx += 1
            else:
                if n - (idx + 1) < (count - 1): # remaining data is too few.
                    return False
                else: # check whether are (count - 1) data which begins with '01'.
                    j = 1
                    while(j < count):
                        if self.countFirstOne(bis[idx + j]) != 1:
                            return False
                        else:
                            j += 1
                idx = idx + count

        return True




sol = Solution()
data = [230, 136, 145]
print sol.validUtf8(data)
