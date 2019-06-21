class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        #动态规划
        matched_index=dict()  #已经匹配过了的下标记录
        def dp(i,j):
            if (i,j) in matched_index : return matched_index[(i,j)]
            if j == len(p) : return i == len(s)
            
            first = i < len(s) and p[j] in {s[i],'.'}       #和普通字符或者.的匹配
            
            if j <= len(p)-2 and p[j+1] == '*':              #和*的匹配
                ans = dp(i, j+2) or (first and dp(i+1,j))
            else:
                ans = first and dp(i+1,j+1)
            
            matched_index[(i,j)] = ans
            return ans
                                     
        return dp(0,0)