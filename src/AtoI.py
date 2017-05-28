class Solution(object):


    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        x=0
        if len(str) == 0:
            return  0
        while str[0] == ' ':
            flag = 1
            str = str[1:]

        if str[0] == '-':
            flag = -1
            str = str[1:]
        elif '0' <= str[0] <= '9':
            flag = 1
        elif str[0] == '+' or str[0] == ' ':
            flag = 1
            str = str[1:]
        else:
            return  0
        for s in str:
            if s < '0' or s > '9':
                break
            else:
                x *= 10
                x += ord(s) - 48
        x  *= flag

        if x >= (1<<31):
            return (1<<31)-1
        elif x <= ~(1<<31):
            return ~(1<<31) +1
        else:
            return  x
if __name__ == '__main__':
    sol = Solution()
    print sol.myAtoi("-2147483649")

