class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        
        
        intervals.sort(key=lambda x: x[1])
        lastend = intervals[0][1]
        res = 1
        for i in range(1,len(intervals)):
            if lastend<=intervals[i][0]:
                res += 1 
                lastend = intervals[i][1]
            
    
        return len(intervals)-res