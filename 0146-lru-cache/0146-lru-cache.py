class Node:
    def __init__(self, k, v):
        self.key = k
        self.val = v
        self.prev = None
        self.next = None
          
class LRUCache:

    def __init__(self, capacity: int):
        self.cache = {}
        self.head = Node(-1,-1)
        self.tail = Node(-1,-1)
        # self.head.prev = self.head
        self.head.next = self.tail
        self.tail.prev = self.head
        # self.tail.next = self.tail
        self.cap = capacity

    def get(self, key: int) -> int:
        if key in self.cache: 
            self.remove(self.cache[key])
            self.append(self.cache[key])
            return self.cache[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache: 
            self.remove(self.cache[key])
            self.append(self.cache[key])
            self.cache[key].val = value
        else:
            if len(self.cache)==self.cap: 
                self.cache.pop(self.head.next.key)
                self.remove(self.head.next)
            self.cache[key] = Node(key,value)
            self.append(self.cache[key])
            
    def append(self, nod):
        nod.prev = self.tail.prev
        nod.next = self.tail
        self.tail.prev.next = nod
        self.tail.prev = nod
        
    def remove(self, nod):
        nod.next.prev = nod.prev
        nod.prev.next = nod.next
        
    

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)