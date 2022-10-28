class Solution:
    # @cache
    def superEggDrop(self, k: int, n: int) -> int:
        
#         if k==1 or n<=1: return n

#         l,r,res = 1,n,float('inf')
        
#         while l<=r:
            
#             m = l+(r-l)//2
            
#             a = self.superEggDrop(k-1,m-1)
#             b = self.superEggDrop(k,n-m)

#             if a>b:
#                 r = m-1
#             else:
#                 l = m+1
            
#             res = min(res,1+max(a,b))
            
#         return res

        dp = [[0]*(k+1) for _ in range(n+1)]
        m = 0
        while dp[m][k] < n:
            m+=1
            for i in range(1,k+1):
                dp[m][i] = dp[m-1][i-1] + dp[m-1][i] + 1 
                
        return m