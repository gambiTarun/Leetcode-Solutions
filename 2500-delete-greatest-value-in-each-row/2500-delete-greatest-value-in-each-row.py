class Solution:
    def deleteGreatestValue(self, grid: List[List[int]]) -> int:
        for r in grid:
            r.sort()
            
        print(grid)
        ans = 0
        for c in range(len(grid[0])):
            x = 0
            for r in range(len(grid)):
                x = max(x,grid[r][c])
            ans += x
            
        return ans