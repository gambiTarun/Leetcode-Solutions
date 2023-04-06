class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size(),res=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res = max(res, dfs(grid,i,j));
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>> &g, int r, int c){
        if(r<0 || c<0 || r>=g.size() || c>=g[0].size() || g[r][c]==0)
            return 0;
        
        g[r][c] = 0;
        
        return dfs(g,r+1,c)+dfs(g,r,c+1)+dfs(g,r,c-1)+dfs(g,r-1,c)+1;
    }
};