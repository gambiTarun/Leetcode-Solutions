class Solution:
    def trap(self, height: List[int]) -> int:
        
        lm,rm = [0]*(len(height)),[0]*(len(height))
        ans = 0
            
        for i in range(len(rm)-2,-1,-1):
            rm[i] = max(rm[i+1],height[i+1])
            
        for i in range(1,len(lm)):
            lm[i] = max(lm[i-1],height[i-1])
            water = min(lm[i],rm[i]) - height[i]
            ans += water if water>0 else 0
    
        return ans