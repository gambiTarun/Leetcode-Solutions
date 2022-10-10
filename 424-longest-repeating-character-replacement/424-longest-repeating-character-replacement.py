class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        
        l = 0
        ans = 0
        lc = [0]*26
        maxcount = 0
        for r in range(len(s)):
            lc[ord(s[r])-ord('A')]+=1
            maxcount = max(maxcount, lc[ord(s[r])-ord('A')])
            # print(ans, maxcount, lc)
            if (r-l+1)-maxcount <= k:
                ans = r-l+1
            else:
                # print(i,ans, s[i-ans+1])
                lc[ord(s[l])-ord('A')]-=1
                l+=1
            
        return ans