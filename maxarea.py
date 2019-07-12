class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        #双指针法，时间复杂度O(n)，每次移动高度低的那边，这样有可能得到更大的面积
        maxarea = 0
        left = 0
        right = len(height) - 1
        while left < right:
            width = right - left
            length = min(height[left], height[right])
            area = width * length
            if area > maxarea:
                maxarea = area
            
            if height[left] < height[right]:
                left+=1
            else:
                right-=1
        
        return maxarea