class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        m = len(board)
        n = len(board[0])
        
        vis = {}
        
        def out(i,j):
            if (i,j) in vis: return vis[(i,j)]
            if i<0 or j<0 or i>=m or j>=n: return True
            if board[i][j]=='X': return False

            surround = False
            vis[(i,j)] = surround
            
            if out(i+1,j) or out(i,j+1) or out(i-1,j) or out(i,j-1):
                surround = True
            
            vis[(i,j)] = surround
            
            return vis[(i,j)]
            
        def flip(i,j):
            if i<0 or j<0 or i>=m or j>=n or board[i][j] == 'X': return 
            
            board[i][j] = 'X'
            
            flip(i+1,j)
            flip(i,j+1)
            flip(i-1,j)
            flip(i,j-1)
            
            
        for i in range(m):
            for j in range(n):
                if board[i][j]=='O' and (i,j) not in vis and not out(i,j):
                    flip(i,j)
                
                    
                    
                    