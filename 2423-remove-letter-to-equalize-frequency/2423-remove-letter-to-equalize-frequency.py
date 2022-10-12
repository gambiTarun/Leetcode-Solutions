class Solution:
    def equalFrequency(self, word: str) -> bool:
        
        def isval(l):
            t = 0
            for p in l:
                if p!=0: 
                    t = p
                    
            for p in l:
                if p!=0 and p!=t: return False
                
            return True
                
        c = [0]*26
        
        for i in word:
            c[ord(i)-ord('a')] += 1
            
        for i in range(26):
            c[i]-=1
            if isval(c): return True
            c[i]+=1
        
        return False