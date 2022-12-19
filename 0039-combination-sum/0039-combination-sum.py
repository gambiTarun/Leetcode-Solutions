class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
        def backtrack(t,li,s):
            if t<0:
                return
            if t==0:
                ans.append(li.copy())
                return
            for i in range(s,len(candidates)):
                li.append(candidates[i])
                backtrack(t-candidates[i],li,i)
                li.pop()
                
        ans = []
        
        backtrack(target,[],0)
        
        return ans