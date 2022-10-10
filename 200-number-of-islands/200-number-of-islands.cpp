class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    vector<vector<bool>> visi(m,vector<bool>(n,false));
                    floodfill(grid,visi,i,j);
                    ans++;
                }
            }
        }
        
        return ans;
    }
    
    void floodfill(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j){
        // cout<<i<<","<<j<<endl;
        if (i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j] || grid[i][j]=='0')
            return;
        vis[i][j]=true;
        grid[i][j]='0';
        floodfill(grid,vis,i+1,j);
        floodfill(grid,vis,i-1,j);
        floodfill(grid,vis,i,j+1);
        floodfill(grid,vis,i,j-1);
    }
};