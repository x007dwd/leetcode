class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        flag = x >=0
        print x
        if not flag:
            x = -x
        if x >= 2**31 - 1:
            return 0
        print (2**31-1)
        t = 0
        while x/10:
            t *= 10
            t += x%10
            x /= 10
        t *= 10
        t += x % 10
        if not flag:
            t=-t
        return t
if __name__ == '__main__':
    sol = Solution()
    print sol.reverse(1534236469)