class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        
        ans,l,r = [],0,len(s)
        
        for c in s:
            if c=='I':
                ans.append(l)
                l+=1
            else:
                ans.append(r)
                r-=1
                
        ans += [l] if s[-1]=='I' else [r]
        
        return ans