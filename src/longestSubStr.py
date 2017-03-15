class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        sst = []
        sdct= dict()
        maxl = 0
        tl = 0
        for st in s:
            if st in sst:
                tmp = sst.index(st)
                sst = sst[tmp+1:]
            sst.append(st)
            maxl = max(maxl, len(sst))
        print  sst
        return  maxl

s = 'bbbbbcbsadbxux'
su = Solution()
print  su.lengthOfLongestSubstring(s)