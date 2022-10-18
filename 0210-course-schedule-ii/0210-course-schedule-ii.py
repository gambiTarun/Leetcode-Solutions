class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        
        d = {i: [] for i in range(numCourses)}
        vis = {i: 0 for i in range(numCourses)}
        
        for crs, pre in prerequisites:
            d[crs].append(pre)
            
        res = []
        
        def dfs(i):
            if vis[i]==1:
                return True
            
            if vis[i]==0:
                vis[i]=1
                for x in d[i]:
                    if dfs(x):
                        return True
                    
                vis[i] = 2
                
                res.append(i)
                
            return False
        
        for i in range(numCourses):
            if dfs(i):
                return []
            
        return res