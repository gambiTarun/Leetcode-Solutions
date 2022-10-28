class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        
        
#         def check(curr):
#             if curr==corrm: return 0
            
#             if curr+60<=corrm:
#                 return check(curr+60)+1 
#             elif curr+15<=corrm:
#                 return check(curr+15)+1 
#             elif curr+5<=corrm:
#                 return check(curr+5)+1 
            
#             return check(curr+1)+1 
            
            
        
#         currm = sum([int(t)*m for t,m in zip(current.split(":"),[60,1])])
#         corrm = sum([int(t)*m for t,m in zip(correct.split(":"),[60,1])])
        
        
#         return check(currm)

        currm = sum([int(t)*m for t,m in zip(current.split(":"),[60,1])])
        corrm = sum([int(t)*m for t,m in zip(correct.split(":"),[60,1])])
        tar = corrm-currm
        
        dp = [1441]*(tar+1)
        dp[0] = 0
        for i in range(tar+1):
            for j in [60,15,5,1]:
                if i>=j:
                    dp[i] = min(dp[i],dp[i-j]+1)
                    
        return dp[tar]
        