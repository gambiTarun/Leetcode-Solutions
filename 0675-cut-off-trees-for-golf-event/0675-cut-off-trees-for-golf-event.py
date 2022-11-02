class Solution:
    def cutOffTree(self, forest: List[List[int]]) -> int:
        
        m = len(forest)
        n = len(forest[0])
        
        
        def dist(s,t):
            if s==t:
                return 0
            q = deque()
            q.append(s)
            d = 0
            vis = set()
            vis.add(s)
            while q:
                d+=1
                siz = len(q)
                for _ in range(siz):
                    i,j = q.popleft()
                    for dr,dc in [(1,0),(0,1),(-1,0),(0,-1)]:
                        r = i+dr
                        c = j+dc
                        if (r,c)==t:
                            return d
                        if 0<=r<m and 0<=c<n and (r,c) not in vis and forest[r][c]!=0:
                            vis.add((r,c))
                            q.append((r,c))

            return -1
        
        trees = sorted((v,r,c) for r,row in enumerate(forest) for c,v in enumerate(row) if v>1)
        sr = sc = res = 0
        for _,tr,tc in trees:
            dis = dist((sr,sc),(tr,tc))
            if dis==-1:
                return -1
            res += dis
            sr,sc = tr,tc
        
        return res