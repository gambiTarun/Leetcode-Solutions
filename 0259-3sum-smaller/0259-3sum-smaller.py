class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        
        nums.sort()
        ans = 0
        for i,v in enumerate(nums):
            l,r = i+1,len(nums)-1
            
            while l<r:
                m = l+(r-l)//2
                s = v+nums[l]+nums[r]
                
                if s>=target:
                    r-=1
                else:
                    ans+=r-l
                    l+=1
        return ans