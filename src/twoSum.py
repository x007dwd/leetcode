class Solution(object):
    def twoSumBruteForce(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        sz = len(nums)
        for i in range(sz):
            for k in range(i+1,sz):
                if nums[i] +  nums[k] == target:
                    return  i,k
        if i == sz:
            return -1
    def twoSumHash(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        sz = len(nums)
        dct = dict()
        for i in range(sz):
            dct[nums[i]] = i

        for i in range(sz):
            res = target - nums[i]
            if res in dct and dct[res] != i:
                return  i,dct[res]
        if i == sz:
            return -1

    def twoSumHash2(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        sz = len(nums)
        dct = dict()
        for i in range(sz):
            res = target - nums[i]
            if res in dct and dct[res] != i:
                return  i,dct[res]
            dct[nums[i]] = i
        if i == sz:
            return -1
if __name__=='__main__':
    nums = [3,2,4]
    target = 6
    sl = Solution()
    print  sl.twoSumHash(nums,target)
