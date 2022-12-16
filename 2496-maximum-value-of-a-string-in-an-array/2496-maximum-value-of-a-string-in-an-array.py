class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        return max([int(i) if not any([c.isalpha() for c in i]) else len(i) for i in strs ])