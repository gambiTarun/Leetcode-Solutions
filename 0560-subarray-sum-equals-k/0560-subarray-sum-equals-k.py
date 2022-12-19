class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        
        d = defaultdict(int)
        d[0] = 1
        ans,s = 0,0
        for i in nums:
            s += i
            if s-k in d:
                ans += d[s-k]
                
            d[s] += 1
            
        return ans