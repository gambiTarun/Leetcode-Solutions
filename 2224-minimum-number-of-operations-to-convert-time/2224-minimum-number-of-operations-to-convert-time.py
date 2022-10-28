class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        
        
        def check(curr):
            if curr==corrm: return 0
            
            if curr+60<=corrm:
                return check(curr+60)+1 
            elif curr+15<=corrm:
                return check(curr+15)+1 
            elif curr+5<=corrm:
                return check(curr+5)+1 
            
            return check(curr+1)+1 
            
            
                
        
        currm = sum([int(t)*m for t,m in zip(current.split(":"),[60,1])])
        corrm = sum([int(t)*m for t,m in zip(correct.split(":"),[60,1])])
        
        
        return check(currm)
        