class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        # sz1 = len(nums1)
        # sz2 = len(nums2)
        # mdn1 = sz1 / 2
        # mdn2 = sz2 / 2
        # if mdn1 == 1:
        #     if nums1[0] > nums2[mdn2]
        #         if sz2%2:
        #             return  nums2[mdn2]
        #         else:
        #             return 0.5 *(nums2[mdn2] + nums2[mdn2-1])
        #     else:
        nums1 = (nums1+nums2)
        nums1 = sorted(nums1)
        print  nums1
        sz = len(nums1)
        print  sz
        if sz%2 == 0:
            return 0.5*(nums1[sz/2]+nums1[sz/2-1])
        else:
            return nums1[sz/2]
    def findMedianSortedArrays2(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        sz1 = len(nums1)
        sz2 = len(nums2)
        if (sz1+sz2)%2==0:
            return 0.5*(self.find_font_k(nums2,nums1,(sz1+sz2)/2)+self.find_font_k(nums1,nums2,(sz1+sz2)/2+1))
        else:
            return self.find_font_k(nums1,nums2,(sz1+sz2)/2+1)

    def find_font_k(self,nums1,nums2,k):
        if len(nums1) > len(nums2):
            return  self.find_font_k(nums2,nums1,k)
        if len(nums1) ==0 : return nums2[k-1]
        if k==1: return min(nums1[0],nums2[0])
        ia = min(len(nums1),k/2)
        ib = k- ia


        if nums1[ia-1] < nums2[ib-1]:
            return  self.find_font_k(nums1[ia:],nums2,k-ia)
        elif nums1[ia-1] > nums2[ib-1]:
            return  self.find_font_k(nums1,nums2[ib:],k-ib)
        else:
            return nums2[ib-1]

num1=[1,4,7,10,59,100]
num2 = [2,4,5,7,8,10,11,12,17]
s = Solution()
print  s.findMedianSortedArrays(num1,num2)
print s.findMedianSortedArrays2(num1,num2)