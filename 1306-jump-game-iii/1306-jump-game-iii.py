class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        
        q = deque()
        
        q.append(start)
        
        while q:
            i = q.popleft()
            
            if not 0<=i<len(arr) or arr[i]==-1:   
                continue
            
            if arr[i] == 0:
                return True
            m = arr[i]
            arr[i]=-1
            
            q.append(i-m)
            q.append(i+m)