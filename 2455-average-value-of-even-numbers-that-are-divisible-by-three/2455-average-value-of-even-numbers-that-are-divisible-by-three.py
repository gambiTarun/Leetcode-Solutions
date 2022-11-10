class Solution:
    def averageValue(self, nums: List[int]) -> int:
        a = [n for n in nums if n%6==0]
        return sum(a)//len(a) if a else 0