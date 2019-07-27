class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        size=len(nums)
        i = size-2
        while i>=0 and nums[i+1]<=nums[i]:        #找到第一个非逆序的位置
            i-=1
        if i >= 0:
            j = size-1
            while j >= 0:                           #找到比非逆序位置的数字和其他逆序数字中和自己差距最小的
                if nums[j] <= nums[i]:
                    j-=1
                else:
                    break
            nums[i],nums[j]=self.swapNum(nums[i],nums[j])   
        
        return self.revertList(nums, i + 1, size-1)      #将逆序部分颠倒为顺序
    def swapNum(self, num1, num2):
        tmp = num1
        num1 = num2
        num2 = tmp
        return num1,num2
    def revertList(self, nums, begin, end):
        while begin<end:
            nums[begin],nums[end]=self.swapNum(nums[begin],nums[end])
            begin+=1
            end-=1
        return nums
            