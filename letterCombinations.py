class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        
        numberdict = {
            "2" : "abc",
            "3" : "def",
            "4" : "ghi",
            "5" : "jkl",
            "6" : "mno",
            "7" : "pqrs",
            "8" : "tuv",
            "9" : "wxyz"
        }
        
        size = len(digits)
        res=[]
        //递归函数
        def recursion(i, tmp):
            if i == size:
                res.append(tmp)
                return
            for mem in numberdict[digits[i]]:
                recursion(i + 1, tmp + mem) 
                
        recursion(0,"")
        return res