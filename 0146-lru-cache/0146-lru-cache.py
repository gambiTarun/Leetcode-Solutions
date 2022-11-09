# class LL:
#     def __init__(self):
#         self.val = None
#         self.prev = self
#         self.next = self
#         self.len = 0
        
#     def append(self, val):
#         self.val = val
#         self.prev = prev
#         self.next = nex
#         self.len += 1
        
#     def pop(self):
        
    
class LRUCache:

    def __init__(self, capacity: int):
        self.cache = {}
        self.q = deque()
        self.cap = capacity

    def get(self, key: int) -> int:
        if key in self.cache: 
            self.q.remove(key)
            self.q.append(key)
            return self.cache[key]
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache: 
            self.q.remove(key)
            self.q.append(key)
            self.cache[key] = value
        
        else:
            if len(self.q)==self.cap: 
                self.cache.pop(self.q[0])
                self.q.popleft()
            self.q.append(key)
            self.cache[key] = value

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)