class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        #i是最左边的，left是中间的数，right是右边的数
        i = 0
        for i in range(len(nums)):
            if i == 0 or nums[i] > nums[i-1]:
                left = i + 1
                right = len(nums)-1
                if nums[0] > 0:
                    break;
            
                while left < right:
                    tmp = nums[i] + nums[left] + nums[right]
                    if tmp == 0:
                        res.append([nums[i], nums[left], nums[right]])
                        left+=1
                        right-=1
                        while left < right and nums[left] == nums[left-1]:
                            left+=1
                        while left < right and nums[right] == nums[right+1]:
                            right-=1
                    elif tmp > 0:
                        right-=1
                    else:
                        left +=1
        
        return res