class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        
        r = [1 for x in range(rowIndex+1)]
        
        for i in range(1,rowIndex):
            
            for j in range(i,0,-1):
                r[j] += r[j-1]
                
            
        return r