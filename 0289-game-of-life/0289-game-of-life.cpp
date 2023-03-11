class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<i<<","<<j<<endl;
                alive(board,i,j);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]<0)
                    board[i][j]=1;
                else if(board[i][j]>1)
                    board[i][j]=0;
            }
        }
    }
    void alive(vector<vector<int>>&b, int i, int j){
        vector<int> dirs[]={{1,1},{1,-1},{-1,1},{-1,-1},{0,-1},{0,1},{1,0},{-1,0}};
        int n=0;
        for(auto d:dirs){
            
            int ni = i+d[0];
            int nj = j+d[1];
            // cout<<ni<<","<<nj<<endl;
            if(ni>=0 && nj>=0 && ni<b.size() && nj<b[0].size() && b[ni][nj]>0)
                n++;
        }
        // cout<<n<<endl;
        if(b[i][j]>0 && n>3)
            b[i][j]++;
        if(b[i][j]>0 && n<2)
            b[i][j]++;
        if(b[i][j]<=0 && n==3)
            b[i][j]--;
            
    }
};