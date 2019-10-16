class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        #直接修改原二维数组,每个位置只能从他的上方或者左边而来,那选取上/左较小的则为到达下一个位置的最右位置
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if i == 0 and j == 0:
                    continue
                elif i == 0:
                    grid[i][j] = grid[i][j]+grid[i][j-1]
                elif j == 0:
                    grid[i][j] = grid[i][j]+grid[i-1][j]
                else:
                    tmp = min(grid[i-1][j],grid[i][j-1])
                    grid[i][j] = grid[i][j]+tmp
        return grid[-1][-1]