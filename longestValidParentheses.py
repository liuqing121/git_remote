class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        #左右遍历计数法 时间复杂度O(2n),空间复杂度O(1)
        left = 0
        right = 0
        index = 0
        maxlen = 0
        while index < len(s):
            if s[index] == '(':
                left+=1
            else:
                right+=1
            if left == right:
                maxlen = max(maxlen,2*right)
            elif right>left:
                left=right=0
            index+=1
        
        index-=1
        left=right=0
        while index > 0:
            if s[index] == '(':
                left+=1
            else:
                right+=1
            if left == right:
                maxlen = max(maxlen,2*right)
            elif left>right:
                left=right=0
            index-=1
        return maxlen