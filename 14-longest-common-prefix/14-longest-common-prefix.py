class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        res = strs[0]
        for s in strs:
            res = res[:len(s)]
            for i in range(len(s)):
                if i==len(res) or s[i]!=res[i]:
                    res = res[:i]
                    break
                    
        return res