class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        
        res = []
        
        for i in range(numRows):
            r = [1 for i in range(i+1)]
            
            for j in range(1,i):
                r[j] = res[i-1][j-1] + res[i-1][j]
                
            res.append(r)
            
        return res
            