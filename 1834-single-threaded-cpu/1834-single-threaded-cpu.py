class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        
        alltasks = sorted([(t[0],t[1],i) for i,t in enumerate(tasks)])
        nexttask = []
        ans = []
        i = 0
        ctime = alltasks[i][0]
        
        while len(ans)<len(alltasks):
            while i<len(tasks) and ctime>=alltasks[i][0]:
                heapq.heappush(nexttask, (alltasks[i][1],alltasks[i][2]))
                i+=1
                
            if nexttask:
                t, idx = heapq.heappop(nexttask)
                ctime+=t
                ans.append(idx)
            else:
                ctime = alltasks[i][0]
                
        return ans