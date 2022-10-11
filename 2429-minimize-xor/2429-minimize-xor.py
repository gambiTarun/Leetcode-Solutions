class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        
        b1 = format(num1,"032b")
        b2 = format(num2,"032b")
        
        c1 = sum(1 for i in b1 if i=="1")
        c2 = sum(1 for i in b2 if i=="1")
        
        r = len(b1)-1
        while c1>c2 and r>=0:
            if b1[r]=="1": 
                b1 = b1[:r] + "0" + b1[r+1:]
                c1-=1
            r-=1
            
        r = len(b1)-1
        while c1<c2 and r>=0:
            if b1[r]=="0":
                b1 = b1[:r] + "1" + b1[r+1:]
                c1+=1
            r-=1
    
        return int(b1,2)
                