class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x==0:
            return 0
        str_x = str(x)     #将传入数字转换成字符串
        res = ''
        if str_x[0] == '-':      #若传入数字是负数，先保留负号
            res += '-'
        
        res += str_x[len(str_x)-1::-1].lstrip("0").rstrip("-")   #将原串倒序并且去掉倒序后的左边的所有0，右边的所有负号
        res = int(res)
        if -2147483648<res<2147483647:
            return res
        return 0;