# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if not head:
            return None

        #慢指针法
        fast=slow=head
        count=0
        while fast:
            count=count+1
            fast=fast.next
            if count > n+1:
                slow = slow.next


        if count ==1 and n==1:   #只有一个节点
            return None
        elif n==1:            #删除尾节点
            slow.next=None 
        elif n == count:          #删除头节点
            return head.next
        else:                #删除中间节点
            slow.next = slow.next.next
        return head