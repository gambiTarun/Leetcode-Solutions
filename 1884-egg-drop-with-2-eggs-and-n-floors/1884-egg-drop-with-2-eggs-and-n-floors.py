class Solution:
    def twoEggDrop(self, n: int) -> int:
        
#         dp = [[0]*(n+1) for _ in range(n+1)]
        
#         for i in range(n,-1,-1):
#             for j in range(i,n+1):
#                 dp[i][j] = min([max(x-i,dp[x+1][j])+1 for x in range(i,j)], default=0)
        
#         return dp[0][n]
        
        @lru_cache(None)
        def eggs(f):
            
            return min([1+max(i-1, eggs(f-i)) for i in range(1,f)], default=1)
        
        return eggs(n)