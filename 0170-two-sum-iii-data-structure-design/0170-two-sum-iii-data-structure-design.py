class TwoSum:

    def __init__(self):
        self.d = defaultdict(int)

    def add(self, number: int) -> None:
        self.d[number]+=1

    def find(self, value: int) -> bool:
        for i,v in self.d.items():
            self.d[i]-=1
            print(i,v)
            if value-i in self.d and self.d[value-i]>0:
                self.d[i]+=1
                return True
            self.d[i]+=1
            
        return False


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)