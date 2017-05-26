class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        s_min = ''
        s_max = ''
        if len(s1) < len(s2):
            s_min = s1
            s_max =  s2
        else:
            s_min = s2
            s_max = s1
        d = dict()
        i = 0
        for s in s_min:
            d[s] = i
            i += 1
        j = 0
        for s in s_max:
            k = 0
            dd = dict()
            while d.has_key(s) and (not dd.has_key(s)):
                k += 1
                dd[s] = j
                if k == len(s_min):
                    return  True
                if j+k < len(s_max):
                    s = s_max[j + k]
                else:
                    break
            j += 1
            print  dd
        print  d
        return  False


if __name__ == '__main__':
    s1 = 'abcdxabcde'
    s2 = 'abcdeabcdx'

    sol = Solution()
    print  sol.checkInclusion(s1,s2)



