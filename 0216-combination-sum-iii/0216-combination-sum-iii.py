class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        
        def backtrack(t,li,s):
            if t<0: return
            if t==0 and len(li)==k:
                ans.append(li.copy())
                return
            for i in range(s,10):
                li.append(i)
                backtrack(t-i,li,i+1)
                li.pop()
                
        ans=[]
        backtrack(n,[],1)
        
        return ans