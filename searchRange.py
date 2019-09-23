class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #��������±�
        def searchleft():
            if len(nums) == 0:
                return -1
            left = 0
            right = len(nums) - 1
            while left <= right:
                mid = (left + right)/2
                if nums[mid] == target:      #�ҵ�Ŀ��֮�󲻷��أ������������
                    right = mid
                elif nums[mid] < target:
                    left = mid +1
                elif nums[mid] > target:
                    right = mid -1
                if left == right:
                    if nums[left]==target:          #����û���ҵ������
                        return left
                    else:
                        return -1
            return -1
        
        #���ұߵ��±�
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