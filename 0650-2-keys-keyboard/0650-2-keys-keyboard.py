class Solution:
    @cache
    def minSteps(self, n: int) -> int:
        
        if n==1:
            return 0
            
        return min([i + self.minSteps(n//i) for i in range(2,n) if n%i==0], default=n)