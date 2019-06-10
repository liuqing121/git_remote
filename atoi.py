class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str = str.lstrip(" ")
        if len(str) == 0:
            return 0
        
        i = 0
        symbol = False
        if str[0] == '-':
            symbol = True
            i += 1
        elif str[0] == '+':
            i += 1
            

        res = 0
        while i < len(str) and str[i] <= '9' and str[i] >= '0':
            res = res * 10 + int(str[i])
            i += 1
            
        INT_MAX = 2 << 30
        res = min(INT_MAX, res)
        if symbol:
            res = -res
        
        return res