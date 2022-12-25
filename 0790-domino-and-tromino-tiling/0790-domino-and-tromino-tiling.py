class Solution:
    def numTilings(self, n: int) -> int:
        mod = 1000_000_007
        f = [0]*(n+1)
        p = [0]*(n+1)
        
        f[1] = 1
        
        if n==1:
            return 1
        
        f[2] = 2
        p[2] = 1
        
        for i in range(3,n+1):
            f[i] = (f[i-1] + f[i-2] + 2*p[i-1]) % mod
            p[i] = (p[i-1] + f[i-2]) % mod
        
        return f[n] % mod