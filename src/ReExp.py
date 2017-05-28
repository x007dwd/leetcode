class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if len(p) == 0:
            return  len(s) == 0
        if len(p)>1 and p[1] != '*':
            if p[0] == s[0] or ( p[0] == '.' and s[0] != ''
            isMatch(p[0],)

        return  True
if __name__ == '__main__':

