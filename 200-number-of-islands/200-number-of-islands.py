class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        ans = 0
        
        def dfs(i,j):
            
            if i<0 or j<0 or i>=len(grid) or j>=len(grid[0]) or grid[i][j]=="0":
                return 
            
            grid[i][j]="0"
            
            dirs = [[0,1],[1,0],[-1,0],[0,-1]]
            for di,dj in dirs:
                dfs(i+di, j+dj)
                
            
            
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]=="1":
                    ans+=1
                    dfs(i,j)
                    
        return ans