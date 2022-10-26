class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        
        q = deque()
        
        q.append(start)
        
        while q:
            i = q.pop()
            
            if not 0<=i<len(arr) or arr[i]<0:   
                continue
            
            if arr[i] == 0:
                return True
            arr[i] *= -1
            
            q.append(i-arr[i])
            q.append(i+arr[i])