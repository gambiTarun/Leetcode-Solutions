class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        
        nums.sort()
        ans=0
        # print(nums)
        for i,v in enumerate(nums):
            r = i+2
            if v==0: continue
            for l in range(i+1,len(nums)-1):
                
                while r<len(nums) and v+nums[l]>nums[r]:
                    r+=1
                ans+=r-l-1
                    
        return ans