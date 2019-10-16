class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        #先排序，遍历list，判断重合，若重合则更新区间，不重合则直接算入结果
        res=[]
        if len(intervals) < 2:
            return intervals
        
        intervals.sort()
        left = intervals[0][0]
        right = intervals[0][1]
        for i in range(1,len(intervals)):
            if intervals[i][0] <= right:
                right = max(right, intervals[i][1])
            else:
                res.append([left,right])
                left = intervals[i][0]
                right = intervals[i][1]
        res.append([left,right])
        return res