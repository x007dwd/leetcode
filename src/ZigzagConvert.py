class Solution(object):
    def convert2(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return  s
        N =len(s)
        ssc = list()
        for i in range(numRows):
            ssc +={''}
        print  ssc
        rows = 0
        direct = 1
        for str in s:
            ssc[rows] += str
            if rows == numRows -1:
                direct = -1
            elif rows == 0:
                direct = 1
            rows += direct

        sscc = ''
        for ss in ssc:
            sscc += ss
        return  sscc

    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        N = len(s)
        step = 2 * numRows - 2
        segs = int(N / step) + 1
        sc=''
        i=0
        for i in range(segs):
            if i * step < N:
                sc += s[i * step]
        for j in range(1,numRows-1):
            for i in range(segs):
                if i * step + j < N:
                    sc += s[i * step + j]
                if (i+1) * step - j < N:
                    sc += s[(i+1) * step -j]
        for i in range(segs):
            if i * step + numRows -1 < N :
                sc += s[i * step + numRows -1]
        return sc


if __name__ == '__main__':
    sol= Solution()
    s = 'ABCD'
    print  sol.convert2(s,1)
