class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        def backtrack(nu,li):
            if not nu:
                ans.append(li)
            
            for i in range(len(nu)):
                if i>0 and nu[i]==nu[i-1]:
                    continue
                backtrack(nu[:i]+nu[i+1:],li+[nu[i]])
                    
        ans=[]
        backtrack(nums,[])
        
        return ans