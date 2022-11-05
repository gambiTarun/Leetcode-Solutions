class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        
        cg,lg = 1,0
        c = l = s[0]
        res = 0
        for i in range(1,len(s)):
            c = s[i]
            if c==l:
                cg += 1
            else:
                res += min(lg,cg)
                lg = cg
                cg = 1
            l = c
            
        res += min(lg,cg)
        return res