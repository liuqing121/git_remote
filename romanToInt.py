class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        numdict={"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        numsub={"IV":4,"IX":9,"XL":40,"XC":90,"CD":400,"CM":900}
        
        tmp=s[0]
        res=numdict[s[0]]
        for ch in s[1:]:
            if tmp+ch in numsub:
                res -= numdict[tmp]
                res += numsub[tmp+ch]
            else:
                res += numdict[ch]
            tmp = ch
        return res