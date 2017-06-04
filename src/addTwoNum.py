# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: int
        """
        num1=0
        num2=0
        tmp = l1

        while True:
            num1 += tmp.val
            if tmp.next is  None:
                break
            else:
                tmp = tmp.next
                num1 *= 10
        tmp = l2
        while True:
            num2 += tmp.val
            if tmp.next is  None:
                break
            else:
                tmp = tmp.next
                num2 *= 10
        print  num1,num2
        return  num2+num1
    def addTwoNumbers2(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        rl = ListNode(0)
        num1=0
        num2=0
        tl1 = l1
        tl2 = l2
        trl = rl
        c = 0
        tf1 = True
        tf2 = True
        while tf1 or tf2 or c !=0 :
            tmp = 0

            if tf1 :
                tmp += tl1.val
            if tf2:
                tmp += tl2.val
            tmp += c
            tmpc = tmp % 10
            trl.next = ListNode(tmpc)

            if tl1.next is  None:
                tf1 = False
            else:
                tl1 = tl1.next

            if tl2.next is None:
                tf2 = False
            else:
                tl2 = tl2.next
            c = tmp / 10
            trl = trl.next
        rl = rl.next
        return  num2+num1

l1 = ListNode(2)
l1.next = ListNode(5)
l1.next.next = ListNode(7)

l2 = ListNode(2)
l2.next = ListNode(5)
l2.next.next = ListNode(7)

s =Solution()
print s.addTwoNumbers2(l1,l2)
