class Solution:
    def mostFrequentEven(self, nums: List[int]) -> int:
        c = Counter(a for a in nums if a%2==0)
        return min([i for i,v in c.items() if v==max(c.values())]) if c else -1