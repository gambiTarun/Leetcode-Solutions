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
        dres = Counter(s[l])
        while r!=len(s):
            # print(dt, dres, res, l, r, c)
            if not (dt - dres):
                if (r-l+1)<len(res):
                    res = s[l:r+1]
                c += 1
                if c==len(m): break
                for i in range(l,m[c]):
                    if dres[s[i]] == 1: dres.pop(s[i])
                    else: dres[s[i]] -= 1
                l = m[c]
            else:
                r += 1
                if r==len(s): break
                if s[r] in dres: dres[s[r]] += 1
                else: dres[s[r]] = 1
                
        
        return "" if res==s and (Counter(t) - Counter(res)) else res