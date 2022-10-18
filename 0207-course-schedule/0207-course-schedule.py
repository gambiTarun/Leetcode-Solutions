class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        
        def iscycle(i,vis,d):
            if vis[i]==1:
                return True
            
            if vis[i]==0:
                vis[i] = 1
                for x in d[i]:
                    if iscycle(x,vis,d):
                        return True
                
                vis[i] = 2
            
            return False
            
        
        d = defaultdict(list)
        vis = defaultdict(int)
        
        for req in prerequisites:
            d[req[0]].append(req[1])
            
        
        for i in range(numCourses):
            if iscycle(i,vis,d):
                return False
            
        return True
        