class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        curr,last = [0]*n, matrix[0]
        
        for i in range(1,n):
            for j in range(n):
                curr[j] = min(last[j-1 if j-1>=0 else j],last[j],last[j+1 if j+1<n else n-1]) + matrix[i][j]
            last = curr.copy()
            
        # print(dp)
        return min(last)