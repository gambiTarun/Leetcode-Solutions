class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        to_visit = 0
        si,sj = 0,0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]>=0:
                    to_visit+=1
                if grid[i][j]==1:
                    si,sj=i,j
        
        res = 0
        def dfs(i,j,rem):
            nonlocal res
            
            if i<0 or j<0 or i>=len(grid) or j>=len(grid[0]) or grid[i][j]<0:
                return
            
            if grid[i][j]==2 and rem==1:
                res += 1
                return
            
            tmp = grid[i][j]
            grid[i][j] = -2
            rem -= 1
            
            for di,dj in [(0,1),(1,0),(-1,0),(0,-1)]:
                dfs(i+di,j+dj,rem)
                
            grid[i][j]=tmp
            rem += 1
            
        dfs(si,sj,to_visit)
        
        return res
            
            