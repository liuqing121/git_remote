class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        #填表形式解法，初始第一行第一列都是1，剩下位置是它上面和左边的和，只用一个一维数组做存储，每次只存一行，最后保存的是最后一行
        tmpnum= [1 for _ in range(n)]
        for j in range(1,m):
            for k in range(1,n):
                tmpnum[k]=tmpnum[k]+tmpnum[k-1]
        return tmpnum[n-1]