from collections import defaultdict,deque
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        
#         dt = defaultdict(deque)
#         ds = defaultdict(deque)
#         for i,c in enumerate(t):
#             dt[c].append(i)
            
#         for i,c in enumerate(s):
#             ds[c].append(i)
            
        # print(ds)
        # print([[i,v] for i,v in ds.items() if i in dt])
        
        m = [i for i,v in enumerate(s) if v in t]
        
        # print(m)
        if not m: return ""
        
        c = 0
        l,r = m[c],m[c]
        res = s
        dt = Counter(t)
        ds = Counter(s[l])
        while r!=len(s):
            # print(dt, dres, res, l, r, c)
            if not (dt - ds):
                if (r-l+1)<len(res):
                    res = s[l:r+1]
                c += 1
                if c==len(m): break
                for i in range(l,m[c]):
                    if ds[s[i]] == 1: ds.pop(s[i])
                    else: ds[s[i]] -= 1
                l = m[c]
            else:
                r += 1
                if r==len(s): break
                if s[r] in ds: ds[s[r]] += 1
                else: ds[s[r]] = 1
                
        return "" if res==s and (dt - Counter(res)) else res