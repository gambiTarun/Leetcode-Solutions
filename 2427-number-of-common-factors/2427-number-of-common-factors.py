class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        
        c,res = 1,0
        m = min(a,b)
        while c<=1000 and c<=m:
            if a%c==0 and b%c==0: res+=1
            c+=1
            
        return res