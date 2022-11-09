class Solution:
    def maxDiff(self, num: int) -> int:
        
        n = str(num)
        x=y= "0"
        for i in range(len(n)):
            if "1"<n[i]<="9":
                x = str(n[i])
                break
                
        if x==n[0]: y = "1"
        else:   y = "0"
            
        mini = int(n.replace(x,y))
        print(x,mini)
        
        for i in range(len(n)):
            if "0"<=n[i]<"9":
                x = str(n[i])
                break
        
        y = "9"    
        maxi = int(n.replace(x,y))
        print(x,maxi)
        
        return maxi-mini