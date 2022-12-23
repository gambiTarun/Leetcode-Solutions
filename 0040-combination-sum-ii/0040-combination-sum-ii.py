class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        def backtrack(t,li,s):
            if t<0:
                return
            if t==0:
                ans.append(li)
                return
            
            for i in range(s,len(candidates)):
                if i>s and candidates[i]==candidates[i-1]:
                    continue
                backtrack(t-candidates[i],li+[candidates[i]],i+1)
                
        ans=[]
        backtrack(target,[],0)
        
        return ans