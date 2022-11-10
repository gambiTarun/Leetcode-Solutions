class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        
        res = []
        n = len(intervals)
        
        # insert interval
        for i,v in enumerate(intervals):
            if newInterval[0]<v[0]:
                intervals.insert(i,newInterval)
                break
            
        if len(intervals)==n:
            intervals.append(newInterval)
            
        print(intervals)
        # merge intervals
        for s,e in intervals:
            if not res or s>res[-1][1]:
                res.append([s,e])
            else:
                res[-1][1] = max(res[-1][1],e)
            
        return res