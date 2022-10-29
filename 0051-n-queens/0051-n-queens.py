class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        
        
            
        def check(r,c,col):
            
            for i in range(r):
                
                j = col[i]
                
                if j==c:
                    return False
                
                if abs(j-c)==abs(r-i):
                    return False
                
            return True
        
        def dfs(r,col,res):
            if r==len(col):
                res.append(col.copy())
            else:
                for c in range(n):
                    if check(r,c,col):
                        
                        col[r] = c
                        dfs(r+1,col,res)
        
        res = []
        
        dfs(0,[-1]*n,res)
                    
        for x in range(len(res)):
            res[x] = ["".join(["Q" if j==i else "." for j in range(n)]) for i in res[x]]
        
        return res