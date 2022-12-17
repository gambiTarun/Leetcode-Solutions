class Allocator:

    def __init__(self, n: int):
        self.mem = [-1]*n

    def allocate(self, size: int, mID: int) -> int:
        tmp,spc,prev = -1,0,-1
        for i in range(len(self.mem)):
            if self.mem[i]==-1:
                if tmp==-1:
                    tmp=i
                spc+=1
            if self.mem[i]!=-1 and tmp!=-1:
                tmp = -1
                spc = 0
                
            if spc>=size:
                for j in range(size):
                    self.mem[tmp+j]=mID
                # print(self.mem)
                return tmp
                
            prev = self.mem[i]
                
            
        return -1

    def free(self, mID: int) -> int:
        freed = 0
        for i in range(len(self.mem)):
            if self.mem[i]==mID:
                self.mem[i] = -1
                freed += 1
                
        return freed
                
        
                


# Your Allocator object will be instantiated and called as such:
# obj = Allocator(n)
# param_1 = obj.allocate(size,mID)
# param_2 = obj.free(mID)