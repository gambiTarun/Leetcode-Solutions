class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        # res = strs[0]
        # for s in strs:
        #     res = res[:len(s)]
        #     for i in range(len(s)):
        #         if i==len(res) or s[i]!=res[i]:
        #             res = res[:i]
        #             break
                    
        if not strs:
            return ""
        
        mi = min(strs)
        ma = max(strs)
        
        for i,c in enumerate(mi):
            if c!=ma[i]:
                mi = ma[:i]
                break
                
        return mi