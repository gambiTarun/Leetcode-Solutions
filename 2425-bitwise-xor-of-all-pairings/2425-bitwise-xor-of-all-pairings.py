class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        
        res = 0
        n1 = len(nums1)
        n2 = len(nums2)
        for i in nums1:
            res ^= i
            if n2%2==0: res ^=i
            
        for i in nums2:
            res ^= i
            if n1%2==0: res ^=i
                
                
        return res