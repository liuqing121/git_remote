class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        #思路:看到log n 的时间复杂度想到二分查找
        #但是二分查找是建立在有序前提下
        #所以多次使用二分查找，先找出数组旋转的点,也就是最小的数字，利用旋转后数组的特点。
        #比较目标值和下标为0的数组值，比它小肯定在旋转点到结束段里面
        
        def search_revert_index():
            left = 0
            right = len(nums) -  1
            if nums[left] < nums[right]:   #该数组是未经过旋转的数组
                return 0
            while left<=right:
                mid  = (left + right) //2
                if nums[mid] > nums[mid + 1]:   #找到了
                    return mid+1
                else:
                    if nums[left] > nums[mid]:
                        right = mid - 1
                    else:
                        left = mid + 1

        
        def search_target_index(left, right):
            while left<=right:
                mid = (left + right) //2
                if nums[mid] == target:
                    return mid
                else:
                    if nums[mid] < target:
                        left = mid + 1
                    else:
                        right = mid - 1
            return -1
        if len(nums) == 0:
            return -1
        if len(nums) == 1:
            return 0 if nums[0] == target else -1
        revert_index = search_revert_index()
        if nums[revert_index] == target:
            return revert_index
        if revert_index == 0:
            return search_target_index(0, len(nums)-1)
        elif target > nums[0]:
            return search_target_index(0, revert_index)
        elif target < nums[0]:
            return search_target_index(revert_index, len(nums)-1)
        else:
            return 0