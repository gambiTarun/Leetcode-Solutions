class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        
        def backtrack(li,s):
            if len(li)==k:
                ans.append(li.copy())
                return
                
            for i in range(s,n+1):
                
                li.append(i)
                backtrack(li,i+1)
                li.pop()
                
        ans = []
        backtrack([],1)
        
        return ans