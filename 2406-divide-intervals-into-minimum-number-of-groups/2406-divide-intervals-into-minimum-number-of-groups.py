class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        
        mh = []
        
        for i in sorted(intervals):
            if mh and mh[0]<i[0]:
                heappop(mh)
            heappush(mh,i[1])
        
        return len(mh)