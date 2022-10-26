class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        m = len(board)
        n = len(board[0])
        
#         vis = {}
        
#         def out(i,j):
#             if (i,j) in vis: return vis[(i,j)]
#             if i<0 or j<0 or i>=m or j>=n: return True
#             if board[i][j]=='X': return False

#             surround = False
#             vis[(i,j)] = surround
            
#             if out(i+1,j) or out(i,j+1) or out(i-1,j) or out(i,j-1):
#                 surround = True
            
#             vis[(i,j)] = surround
            
#             return vis[(i,j)]
            
#         def flip(i,j):
#             if i<0 or j<0 or i>=m or j>=n or board[i][j] == 'X': return 
            
#             board[i][j] = 'X'
            
#             flip(i+1,j)
#             flip(i,j+1)
#             flip(i-1,j)
#             flip(i,j-1)
            
            
#         for i in range(m):
#             for j in range(n):
#                 if board[i][j]=='O' and (i,j) not in vis and not out(i,j):
#                     flip(i,j)

        q = deque()
    
        for i in range(m):
            q.append((i,n-1))
            q.append((i,0))
        for j in range(1,n-1):
            q.append((m-1,j))
            q.append((0,j))
            
        while q:
            i,j = q.pop()
            if 0<=i<m and 0<=j<n and board[i][j]=='O':
                board[i][j]='T'
                for di,dj in [[0,1],[1,0],[-1,0],[0,-1]]:
                    q.append((i+di,j+dj))
                    
        for i in range(m):
            for j in range(n):
                if board[i][j]=='T': board[i][j]='O'
                elif board[i][j]=='O': board[i][j]='X'
                    
                    
                    