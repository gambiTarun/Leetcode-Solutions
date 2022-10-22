class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        res = []
        
        def back(s,op,cl):
            if len(s)==2*n: 
                res.append(s)
                return
            
            if op<n: back(s+'(',op+1,cl)
            if op>cl: back(s+')',op,cl+1)
            
            
        back("",0,0)
        return res