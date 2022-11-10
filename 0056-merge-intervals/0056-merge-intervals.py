class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        res = []
        
        for s,e in sorted(intervals):
            if not res or s>res[-1][1]:
                res.append([s,e])
            else:
                res[-1][1] = max(res[-1][1], e)
        
        return res