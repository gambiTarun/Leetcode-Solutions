class LUPrefix:

    def __init__(self, n: int):
        self.status = [0]*n
        self.last = 0

    def upload(self, video: int) -> None:
        self.status[video-1] = 1

    def longest(self) -> int:
        for i in range(self.last, len(self.status)):
            if self.status[i]==0:
                self.last = i
                return self.last
            
        return len(self.status)


# Your LUPrefix object will be instantiated and called as such:
# obj = LUPrefix(n)
# obj.upload(video)
# param_2 = obj.longest()