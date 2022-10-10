class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        
        for l in range(len(logs)-1,0,-1):
            logs[l][1] -= logs[l-1][1]
            
        return max(logs, key=lambda x:(x[1],-x[0]))[0]
            