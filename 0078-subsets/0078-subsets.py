class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
#         def bintoset(x):
#             tmp = []
#             i = 0
#             while x:
#                 if x & 1:
#                     tmp.append(nums[i])
#                 i += 1
#                 x >>= 1
                
#             return tmp
        
#         res = []
#         for i in range((1<<len(nums))):
#             res.append(bintoset(i))
            
#         return res

        res = [[]]
        
        for i in nums:
            res += [x+[i] for x in res]
            
        return res