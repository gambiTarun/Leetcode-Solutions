class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        
        def isisland(i,j):
            
            q = deque()
            q.append((i,j))
            island = True
            
            while q:
                r,c = q.popleft()
                
                vis.add((r,c))
                if r==0 or c==0 or r==len(grid)-1 or c==len(grid[0])-1:
                    island = False
                
                for dr,dc in [[1,0],[0,1],[-1,0],[0,-1]]:
                    a,b = dr+r,dc+c
                    if a>=0 and a<len(grid) and b>=0 and b<len(grid[0]) and grid[dr+r][dc+c]==0 and (dr+r,dc+c) not in vis:
                        q.append((dr+r,dc+c))
        
            return island
        
        vis = set()
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==0 and (i,j) not in vis and isisland(i,j):
                    count += 1
        
        return count
