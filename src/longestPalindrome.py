class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        bit_num = 1
        if x >= 0:
            flag = 1
        else:
            flag = -1
            return  False
        x *= flag
        bs = 1
        xp = x
        while xp/10:
            bit_num += 1
            xp /= 10
            bs *= 10
        print  bit_num, bs

        xp = x
        for i in range(bit_num/2):
            r = xp % 10
            l = x/bs%10
            xp /= 10
            bs /= 10
            if r == l:
                continue
            else:
                return False
        return  True

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        #so = s.copy()
        sr = s[::-1]
        sz = len(s)
        cnt = 0
        maxc = 0
        maxst=''
        sst = ''
        # print  sr
        for i in range(sz):
            for j in range(sz):
                if s[i] == sr[j]:
                    sst += s[i]
                    cnt+=1
                else:
                    if maxc < cnt:
                        maxc = cnt
                        maxst = sst
                    sst=''
                    cnt=0
        print maxc
        return maxst

s = Solution()
string = 'abcdcb'
# print s.longestPalindrome(string)
print s.isPalindrome(5511111111155)