class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        t = []
        for p,s in sorted(zip(position,speed),reverse=True):
            t.append((target-p)/s)
            if len(t)>=2 and t[-1]<=t[-2]:
                t.pop()
        return len(t)