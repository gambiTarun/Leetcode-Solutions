class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        cmax = 1
        cmin = 1
        res = -10
        
        for i in nums:
            cmax,cmin = max(i,cmax*i,cmin*i),min(i,cmax*i,cmin*i)
            # print(cmin,cmax)
            res = max(res,cmax)
            
        return res
            
            
            