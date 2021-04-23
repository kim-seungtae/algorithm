# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        str_num1 = ''
        str_num2 = ''
        while l1:
            str_num1 += str(l1.val)
            l1 = l1.next
        while l2:
            str_num2 += str(l2.val)
            l2 = l2.next
        
        ans_num = int(str_num1[::-1]) + int(str_num2[::-1])
        ans_num = list(map(int, list(str(ans_num))))
        
        cur = ListNode(ans_num[0], None)
        del ans_num[0]
        
        for i in ans_num:
            nxt = ListNode(i, cur)
            cur = nxt
            
        if len(ans_num) == 0:
            return cur
        else:
            return nxt
            