class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        prev = []
        for i in range(rowIndex+1):
            
            r = [1 for x in range(i+1)]
            
            for j in range(1,i):
                r[j] = prev[j-1] + prev[j]
                
            prev=r
            
        return r