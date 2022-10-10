class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        
        ans = 1
        lc = [0]*26
        maxcount = 0
        for i in range(len(s)):
            lc[ord(s[i])-ord('A')]+=1
            maxcount = max(maxcount, lc[ord(s[i])-ord('A')])
            # print(ans, maxcount, lc)
            if ans-maxcount <= k:
                ans+=1
            else:
                # print(i,ans, s[i-ans+1])
                lc[ord(s[i-ans+1])-ord('A')]-=1
            
        return ans-1