class CustomStack:

    def __init__(self, maxSize: int):
        self.st = [-1]*maxSize
        self.sz = 0

    def push(self, x: int) -> None:
        if self.sz<len(self.st):
            self.st[self.sz] = x
            self.sz += 1
            

    def pop(self) -> int:
        if self.sz>0:
            self.sz -= 1
            return self.st[self.sz]
        return -1
        

    def increment(self, k: int, val: int) -> None:
        for i in range(min(k,self.sz)):
            self.st[i] += val
        


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)