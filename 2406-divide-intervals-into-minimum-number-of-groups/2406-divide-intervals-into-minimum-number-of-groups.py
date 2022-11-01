class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        
        intr = [0]*(max(map(max,intervals))+2)
        
        for i in intervals:
            intr[i[0]-1] += 1
            intr[i[1]] -= 1
            
        res = intr[0]
        for i in range(1,len(intr)):
            intr[i] += intr[i-1]
            res = max(res, intr[i])
        
        
        return res