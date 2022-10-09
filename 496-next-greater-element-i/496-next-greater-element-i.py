class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        
        ng = [-1]*len(nums2)
        
        for i in range(len(nums2)):
            for j in range(i,len(nums2)):
                if nums2[j]>nums2[i]:
                    ng[i] = nums2[j]
                    break
            
        ans = []
        for i in range(len(nums1)):
            ans.append(ng[nums2.index(nums1[i])])
        
        
        return ans