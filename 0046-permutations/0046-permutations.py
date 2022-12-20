class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        vis = set()
        def backtrack(li):
            if len(li)==len(nums):
                ans.append(li.copy())
            
            for i in range(len(nums)):
                if i not in vis:
                    li.append(nums[i])
                    vis.add(i)
                    backtrack(li)
                    vis.remove(i)
                    li.pop()
                    
        ans=[]
        backtrack([])
        
        return ans