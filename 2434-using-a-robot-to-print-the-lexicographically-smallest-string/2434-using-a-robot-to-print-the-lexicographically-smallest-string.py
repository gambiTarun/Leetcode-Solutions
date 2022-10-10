
class Solution:
    def robotWithString(self, s: str) -> str:
        
        res = ""
        st = []
        minFromRight = [""]*len(s)
        minFromRight[-1] = s[-1]
            
        for i in range(len(s)-2,-1,-1):
            minFromRight[i] = min(minFromRight[i+1],s[i])
        
        # print(minFromRight)
        for i in range(len(s)):
            while len(st) and st[-1] <= minFromRight[i]:
                res+=st.pop()
            st.append(s[i])
            
        while len(st):
            res+=st.pop()
        
        return res