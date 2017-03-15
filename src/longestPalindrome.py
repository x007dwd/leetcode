class Solution(object):
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
        print  sr
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
print s.longestPalindrome(string)