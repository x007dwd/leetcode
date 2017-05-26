
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
        if x >= (1 << 31):
            return 0
        print (1 << 31)
        print  ~(1 << 31)
        t = 0
        while x/10:
            t *= 10
            t += x%10
            x /= 10
        t *= 10
        t += x % 10
        if t >= (1 << 31):
            return 0
        if not flag:
            t=-t
        return t
if __name__ == '__main__':
    sol = Solution()
    print sol.reverse(1534236469)