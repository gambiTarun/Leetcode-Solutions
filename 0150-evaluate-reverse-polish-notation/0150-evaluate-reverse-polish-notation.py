class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        
        st = []
        res = 0
        for s in tokens:
            if s.isnumeric():
                st.append(int(s))
            elif len(s)>1 and s[0]=='-':
                st.append(-int(s[1:]))
            else:
                if s=="+":
                    a = st.pop()
                    b = st.pop()
                    st.append(a+b)
            
                elif s=="*":
                    a = st.pop()
                    b = st.pop()
                    st.append(a*b)
                
                elif s=="-":
                    a = st.pop()
                    b = st.pop()
                    st.append(b-a)
                
                elif s=="/":
                    a = st.pop()
                    b = st.pop()
                    st.append(int(b/a))
                    
        return st[0]