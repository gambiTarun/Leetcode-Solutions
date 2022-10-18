class Solution:
    def alienOrder(self, words: List[str]) -> str:
        
        d = {}
        
        for x in words[0]:
            if x not in d:
                d[x] = []
                    
        for i in range(len(words)-1):
            w1,w2 = words[i], words[i+1]
            
            l1 = len(w1)
            l2 = len(w2)
            ml = min(len(w1),len(w2))
             
            if w1[:ml]==w2[:ml] and len(w1)>len(w2):
                return ""
            
            for x in w1:
                if x not in d:
                    d[x] = []
                
            for x in w2:
                if x not in d:
                    d[x] = []
                
            for x in range(ml):
                if w1[x]!=w2[x]:
                    d[w2[x]].append(w1[x])
                    break
            
        vis = {i:0 for i in d.keys()}
        
        res = []
        
        def iscycle(i):
            if vis[i]==1:
                return True
            
            if vis[i]==0:
                vis[i]=1
                for x in d[i]:
                    if iscycle(x):
                        return True
                    
                vis[i]=2
                
                res.append(i)
                
            return False
        
        for i in d.keys():
            if iscycle(i):
                return ""
            
        return ''.join(res)