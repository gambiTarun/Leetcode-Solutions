from heapq import *

class MedianFinder:

    def __init__(self):
        self.first = []     # max heap
        self.second = []    # min heap

    def addNum(self, num: int) -> None:
        if len(self.first)==len(self.second):
            heappush(self.first, -heappushpop(self.second, num))
        else:
            heappush(self.second, -heappushpop(self.first, -num))

    def findMedian(self) -> float:
        if len(self.first)==len(self.second):
            return (self.second[0]-self.first[0])/2.0
        else:
            return -self.first[0]

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()