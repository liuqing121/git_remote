class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n==0:
            return []
        
        result = []
        result.append([None])
        result.append(["()"])
        
        for i in range(2,n+1):    # 开始计算i时的括号组合，记为l
            L=[]
            for j in range(i):   #遍历所有可能的括号内外组合
                list1=result[j]
                list2=result[i-1-j]
                for k1 in list1:           #开始具体取内外组合的实例
                    for k2 in list2:
                        if k1==None:
                            k1=""
                        if k2==None:
                            k2=""
                        sublist="("+ k1 + ")" + k2
                        L.append(sublist)
            result.append(L)
        
        return result[n]