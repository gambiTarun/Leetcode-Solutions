class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        def backtrack(li):
            if len(li)==len(nums):
                if li not in ans:
                    ans.append(li.copy())
                return 
            
            for i in range(len(nums)):
                if i not in vis:
                    li.append(nums[i])
                    vis.add(i)
                    backtrack(li)
                    vis.remove(i)
                    li.pop()
                    
        vis=set()
        ans=[]
        backtrack([])
        
        return ans