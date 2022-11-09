class Solution:
    def reverseBits(self, n: int) -> int:

        r = 0
        for i in range(32):
            bit = n&1
            r += bit<<(32-i-1)
            n = n>>1
            if not n:
                break
        
        return r
        