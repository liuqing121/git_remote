class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        #贪心算法,从后往前,初始的格子为最后一个位置,如果下一个数字和所在位置相加大于等于最后一个位置说明下一个位置可到达,一直循环到第一个
        if len(nums) < 1:
            return false
        lastpos = len(nums)-1
        start = len(nums)-2
        while start >= 0:
            if nums[start] + start >= lastpos:
                lastpos = start
            start = start -1
        return lastpos == 0