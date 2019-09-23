class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #查找左边下标
        def searchleft():
            if len(nums) == 0:
                return -1
            left = 0
            right = len(nums) - 1
            while left <= right:
                mid = (left + right)/2
                if nums[mid] == target:      #找到目标之后不返回，继续向左边找
                    right = mid
                elif nums[mid] < target:
                    left = mid +1
                elif nums[mid] > target:
                    right = mid -1
                if left == right:
                    if nums[left]==target:          #处理没有找到的情况
                        return left
                    else:
                        return -1
            return -1
        
        #找右边的下标
        def searchright():
            if len(nums) == 0:
                return -1
            left = 0;
            right = len(nums) - 1
            while left <= right:
                mid = (left + right)/2
                if nums[mid] == target:
                    left = mid + 1
                elif nums[mid] < target:
                    left = mid +1
                elif nums[mid] > target:
                    right = mid -1
            if nums[left -1]==target:
                  return left-1
            else:
                  return -1
            return -1
    

        return [searchleft(), searchright()]